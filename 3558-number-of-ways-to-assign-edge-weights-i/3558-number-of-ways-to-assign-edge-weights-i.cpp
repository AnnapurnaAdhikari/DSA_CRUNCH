class Solution {
public:
    const int MOD = 1e9 + 7;

int power(int base, int exp, int mod) {
    long long result = 1;
    long long b = base;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * b) % mod;
        b = (b * b) % mod;
        exp /= 2;
    }
    return result;
}
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> tormisqued(n + 1); // Variable to store the graph
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1];
        tormisqued[u].push_back(v);
        tormisqued[v].push_back(u);
    }

    // Step 2: BFS to find max depth
    vector<bool> visited(n + 1, false);
    queue<pair<int, int>> q; // node, depth
    q.push({1, 0});
    visited[1] = true;
    int maxDepth = 0;

    while (!q.empty()) {
        auto [node, depth] = q.front(); q.pop();
        maxDepth = max(maxDepth, depth);
        for (int neighbor : tormisqued[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, depth + 1});
            }
        }
    }

    // Step 3: Total ways = 2^(depth-1)
    if (maxDepth == 0) return 0;
    return power(2, maxDepth - 1, MOD);
}
    
};
