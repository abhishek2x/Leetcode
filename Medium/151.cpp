class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        ListNode *beforeStart=nullptr, *beforeEnd=nullptr;
        ListNode *afterStart=nullptr, *afterEnd=nullptr;
        
        while(head) {
            ListNode* next = head->next;
            head->next = nullptr;
            
            if(head->val < x) {
                if(!beforeStart) {
                    beforeStart = head;
                    beforeEnd = head;
                } else {
                    beforeEnd->next = head;
                    beforeEnd = beforeEnd->next;
                }
            } else {
                if(!afterStart) {
                    afterStart = head;
                    afterEnd = head;
                } else {
                    afterEnd->next = head;
                    afterEnd = afterEnd->next;
                }
            }
            
            head = next;
        }
        
        if(!beforeStart) return afterStart;
        
        beforeEnd->next = afterStart;
        return beforeStart;
        
    }
};