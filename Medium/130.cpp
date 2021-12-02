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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;

        ListNode* o = head;
        ListNode* eh = head->next;
        ListNode* e = eh;
        
        while(e && e->next) {
            o->next = o->next->next;
            e->next = e->next->next;
            e = e->next;
            o = o->next;
        }
        
        o->next = eh;
        return head;
    }
};