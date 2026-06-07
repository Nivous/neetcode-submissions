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
    bool hasCycle(ListNode* head) {
        ListNode *curr = head;
        if (head == nullptr)
            return false;
        int count = 1002;
        head->val = 1001;
        while ((curr = curr->next) != nullptr) {
            curr->val = count;
            count++;
            if (curr->next != nullptr && curr->next->val > 1000)
                return true;
        }

        return false;
    }
};
