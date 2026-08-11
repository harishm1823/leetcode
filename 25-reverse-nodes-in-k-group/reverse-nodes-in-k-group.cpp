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
private:
    // Helper function to get the kth node starting from `curr`
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr != nullptr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy;

        while (true) {
            ListNode* kth = getKthNode(groupPrev, k);
            if (kth == nullptr) {
                break; // Fewer than k nodes remaining, leave them as is
            }

            ListNode* groupNext = kth->next;
            
            // Reverse the sublist of k nodes
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            // Connect groupPrev to the newly reversed head (kth node)
            ListNode* tmp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = tmp; // Move groupPrev to the end of the reversed group
        }

        return dummy.next;
    }
};