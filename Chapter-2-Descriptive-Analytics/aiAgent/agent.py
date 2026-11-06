"""
My first AI agent: a tool-using assistant.

How it works (the "agent loop"):
  1. You ask a question.
  2. Claude decides whether it needs a tool.
  3. If yes, we run the tool and give the result back to Claude.
  4. Repeat until Claude has a final answer.

Setup:
  pip install anthropic
  export ANTHROPIC_API_KEY="your-key-here"     (Mac/Linux)
  setx ANTHROPIC_API_KEY "your-key-here"       (Windows, then reopen terminal)
Run:
  python agent.py
"""

import ast
import operator
import random
from datetime import datetime

import anthropic

MODEL = "claude-sonnet-5-5"
client = anthropic.Anthropic()  # reads ANTHROPIC_API_KEY from your environment


# ---------------------------------------------------------------
# STEP 1: Write the tools (plain Python functions)
# ---------------------------------------------------------------

def calculate(expression: str) -> str:
    """Safely evaluate a math expression like '(23 * 7) / 3'."""
    ops = {
        ast.Add: operator.add, ast.Sub: operator.sub,
        ast.Mult: operator.mul, ast.Div: operator.truediv,
        ast.Pow: operator.pow, ast.USub: operator.neg,
        ast.Mod: operator.mod,
    }

    def ev(node):
        if isinstance(node, ast.Constant) and isinstance(node.value, (int, float)):
            return node.value
        if isinstance(node, ast.BinOp) and type(node.op) in ops:
            return ops[type(node.op)](ev(node.left), ev(node.right))
        if isinstance(node, ast.UnaryOp) and type(node.op) in ops:
            return ops[type(node.op)](ev(node.operand))
        raise ValueError("Unsupported expression")

    try:
        return str(ev(ast.parse(expression, mode="eval").body))
    except Exception as e:
        return f"Error: {e}"


def get_current_time() -> str:
    return datetime.now().strftime("%A, %d %B %Y, %I:%M %p")


def roll_dice(sides: int = 6, count: int = 1) -> str:
    rolls = [random.randint(1, sides) for _ in range(count)]
    return f"Rolled {count}d{sides}: {rolls} (total {sum(rolls)})"


# Map tool names to the functions above
TOOL_FUNCTIONS = {
    "calculate": calculate,
    "get_current_time": get_current_time,
    "roll_dice": roll_dice,
}

# ---------------------------------------------------------------
# STEP 2: Describe the tools to Claude (name, purpose, inputs)
# ---------------------------------------------------------------

TOOLS = [
    {
        "name": "calculate",
        "description": "Evaluate a math expression exactly. Use for any arithmetic.",
        "input_schema": {
            "type": "object",
            "properties": {
                "expression": {"type": "string", "description": "e.g. '(23 * 7) / 3'"}
            },
            "required": ["expression"],
        },
    },
    {
        "name": "get_current_time",
        "description": "Get the current local date and time.",
        "input_schema": {"type": "object", "properties": {}},
    },
    {
        "name": "roll_dice",
        "description": "Roll one or more dice.",
        "input_schema": {
            "type": "object",
            "properties": {
                "sides": {"type": "integer", "description": "Sides per die (default 6)"},
                "count": {"type": "integer", "description": "Number of dice (default 1)"},
            },
        },
    },
]

# ---------------------------------------------------------------
# STEP 3: The agent loop
# ---------------------------------------------------------------

def run_agent(messages: list) -> str:
    while True:
        response = client.messages.create(
            model=MODEL,
            max_tokens=1000,
            system="You are a helpful assistant. Use your tools whenever they help.",
            tools=TOOLS,
            messages=messages,
        )

        # Save Claude's reply in the conversation history
        messages.append({"role": "assistant", "content": response.content})

        # If Claude didn't ask for a tool, we're done
        if response.stop_reason != "tool_use":
            return "".join(b.text for b in response.content if b.type == "text")

        # Otherwise, run every tool Claude asked for
        tool_results = []
        for block in response.content:
            if block.type == "tool_use":
                print(f"  [using tool: {block.name} {block.input}]")
                result = TOOL_FUNCTIONS[block.name](**block.input)
                tool_results.append({
                    "type": "tool_result",
                    "tool_use_id": block.id,
                    "content": str(result),
                })

        # Send the results back and loop again
        messages.append({"role": "user", "content": tool_results})


# ---------------------------------------------------------------
# STEP 4: Chat in the terminal
# ---------------------------------------------------------------

if __name__ == "__main__":
    print("Agent ready! Type 'quit' to exit.\n")
    history = []
    while True:
        user_input = input("You: ").strip()
        if user_input.lower() in {"quit", "exit"}:
            break
        if not user_input:
            continue
        history.append({"role": "user", "content": user_input})
        print("Agent:", run_agent(history), "\n")