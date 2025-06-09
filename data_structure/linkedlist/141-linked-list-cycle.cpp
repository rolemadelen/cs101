/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 풀이 1
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *temp = head;

        int cnt = 1;
        while(temp && cnt < 10001) {
            temp = temp->next;
            cnt += 1;
        }

        return temp ? true : false;
    }
};

// 풀이 2
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *hare = head;
        ListNode *tortoise = head;

        while (hare || tortoise) {
            if (hare) hare = hare->next;
            if (hare) hare = hare->next;
            if (tortoise) tortoise = tortoise->next;

            if (hare != nullptr && hare == tortoise) return true;
        }

        return false;
    }
};