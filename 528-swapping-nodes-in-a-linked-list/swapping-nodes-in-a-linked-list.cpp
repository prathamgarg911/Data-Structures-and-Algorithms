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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy = head;
        ListNode* lastptr = head;
        ListNode* startptr = head;
        int count = 0;
        while(dummy != NULL){
            dummy = dummy->next;
            count++;
        }
        int lastpos = count - k;
        int startpos = k;
        while(lastpos > 0){
            lastptr = lastptr->next;
            lastpos--;
        }
        while(startpos > 1){
            startptr = startptr->next;
            startpos--;
        }
        int swap = lastptr->val;
        lastptr->val = startptr->val;
        startptr->val = swap;
        return head;
    
    }
};