/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* midLL(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reversedLL(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* temp = NULL;

        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr= temp;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        ListNode* curr = reversedLL(midLL(head));
        int maxSum = -1;
        while(curr){
            maxSum = max(maxSum, curr->val + head->val);
            curr= curr->next;
            head = head->next;
        }
        return maxSum;
        
    }
};