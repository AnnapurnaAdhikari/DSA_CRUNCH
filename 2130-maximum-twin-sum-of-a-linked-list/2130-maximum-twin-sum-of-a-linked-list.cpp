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
    int pairSum(ListNode* head) {
        vector<int>nodes;
        while(head){
            nodes.push_back(head->val);
            head = head->next;
        }
        int maxSum = 0;
        int currSum = 0;
        int n = nodes.size();
        for(int i = 0; i <= (n/2 -1); i++){
            currSum = nodes[i] + nodes[n-i-1];
            // cout<<"curr: "<<currSum;
            maxSum = max(maxSum, currSum);
        }
        // cout<<"Max: "<<maxSum;
        return maxSum;
    }
};