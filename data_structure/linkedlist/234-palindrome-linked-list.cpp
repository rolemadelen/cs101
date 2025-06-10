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

// 풀이 1
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *temp = head;
        string s = "";

        while(temp) {
            s += to_string(temp->val);
            temp = temp->next;
        }

        string s2 = s;
        reverse(s2.begin(), s2.end());

        return s == s2;
    }
};


// 풀이 2
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode *slow = head;
        ListNode *fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = nullptr;
        while(slow) {
            cout << "slow: " << slow->val << endl;
            ListNode *next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        ListNode *p = head;
        ListNode *q = prev;
        while(q) {
            if (p->val != q->val) return false;
            p = p->next;
            q = q->next;
        }

        return true;
    }
};
