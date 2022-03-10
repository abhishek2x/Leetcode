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
        
        if(!head) return nullptr;
        
        ListNode* start, *end, *temp=head;
        int length=0;
        
        while(temp) {
            length++;
            end = temp;
            temp = temp->next;
        }
        
        end->next = head;
        temp = head;
        
        if(k >= length) k = k%length;
        int offset = (length-k);
        
        while(temp) {
            if(offset == 1) {
                start = temp->next;
                temp->next = nullptr;
            }
            offset--;
            temp = temp->next;
        }
        
        return start;
    }
};