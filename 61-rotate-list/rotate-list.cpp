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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }

        // 1. Compute the length of the list and locate the tail
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // 2. Connect tail to head to form a circular list
        tail->next = head;

        // 3. Find the new tail: (length - k % length - 1) steps from head
        int stepsToNewTail = length - (k % length) - 1;
        ListNode* newTail = head;
        for (int i = 0; i < stepsToNewTail; ++i) {
            newTail = newTail->next;
        }

        // 4. Set the new head and break the ring
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};