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
        if(!head || !head->next) return head;
        
        ListNode* oH = head;
        ListNode* eH = head->next;
        
        ListNode* oI = oH;
        ListNode* eI = eH;
        
        ListNode* iterator = head->next->next;
        
        int i = 1;
        while(iterator) {
            if(i%2) {
                oI->next = iterator;
                oI = oI->next;
            } else {
                eI->next = iterator;
                eI = eI->next;
            }
            iterator = iterator->next;
            i++;
        }
        
        oI->next = eH;
        eI->next = nullptr;
        
        return oH;
    }
};