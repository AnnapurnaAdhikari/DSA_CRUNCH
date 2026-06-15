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
//approach1:
    // ListNode* midNode(ListNode* head){
    //     ListNode* fast = head;
    //     ListNode* slow = head;
    //     while(fast && fast->next){
    //         fast = fast->next->next;
    //         slow = slow->next;
    //     }
    //     return slow; //second middle
    // }
    // ListNode* deleteMiddle(ListNode* head) {
    //     if(head == NULL || head->next == NULL)
    //         return NULL;
    //     ListNode* mid = midNode(head);
    //     // cout<<mid->val<<" ";
    //     ListNode* temp = head;
    //     while(temp->next != mid){
    //         temp = temp->next;
    //     }
    //     // cout<<temp->val<<" ";
    //     temp->next = mid->next;
    //     delete mid;
    //     return head;    }
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* fast = head, *slow = head;

        if (fast->next == NULL) return NULL;
        fast = fast->next->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return head;
        }
};