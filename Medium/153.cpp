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
    
    
    pair<ListNode*, ListNode*> reversed(ListNode* head) {
        
        ListNode* prev=nullptr;
        ListNode* curr=head;
        
        while(curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            if(temp) curr = temp;
            else break;
        }
        
        return {curr, head};
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left >= right) return head;
        
        ListNode *beforeStart, *beforeEnd, *after = head, *slow; 
        
        if(left == 1) beforeStart = nullptr;
        else beforeStart = head;
        
        int c=0;
        while(after) {
            c++;
                    
            if(c == left) {
                slow=after;
            }
            
            if(c == right) {
                break;
            }
            
            // Set beforeEnd and next            
            if(c == left-1) {
                beforeEnd = after;
                ListNode* temp = after->next;
                after->next = nullptr;
                after = temp;
            }
            else {
                after = after->next;
            }
        }
        
    
        // remove after's prev node's next
        ListNode* temp = after->next;
        after->next = nullptr;
        after = temp;
        
        
        // reversing
        pair<ListNode*, ListNode*> lstPair = reversed(slow);
        
        if(beforeStart) beforeEnd->next = lstPair.first;
        else beforeStart = lstPair.first;
        if(after) lstPair.second->next = after;
        
        return beforeStart;
    }
};