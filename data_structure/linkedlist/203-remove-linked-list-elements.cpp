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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return nullptr;
        
        ListNode *ans = new ListNode(0);
        ListNode *temp = ans;

        while(head) {
            if (head->val != val) {
                temp->next = new ListNode(head->val);
                temp = temp->next;
            }
            head = head->next;
        }

        return ans->next;
    }
};