/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return nullptr;
        
        // check cycle
        
        bool isCycle = false;
        ListNode *slow=head, *fast=head, *intersecting;
        
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                isCycle = true;
                intersecting = slow;
                break;
            }
        }
        
        if(!isCycle) return nullptr;
        
        while(true) {
            if(intersecting == head) return intersecting;
            intersecting = intersecting->next;
            head = head->next;
        }
        
        return intersecting;
    }
};