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
    void insertToList(ListNode* b, ListNode* a) {
        a->next = b->next;
        b->next = a;
    }

    void removeFromList(ListNode *b, ListNode * a) {
        b->next = a->next;
        a->next = nullptr;
    }

    void reorderList(ListNode* head) {
        int n = 0;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        stack<ListNode*> nodes;

        while (curr != nullptr) {
            n++;
            curr = curr->next;
        }

        curr =head;
        int i = 0;

        while (curr != nullptr) {
            
            if (i > n/2) {
                removeFromList(prev, curr);
                nodes.push(curr);
                curr = prev->next;

            } else{
                prev = curr;
                curr = curr->next;
            }
            i++;
        }

        curr = head;
        while(!nodes.empty()) {
            ListNode* next_one = nodes.top();
            nodes.pop();
            insertToList(curr, next_one);
            curr = next_one->next;
        }
    }
};
