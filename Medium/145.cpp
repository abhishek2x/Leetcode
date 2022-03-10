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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        
        unordered_map<int, int> mp;
        
        ListNode* start = head;
        while(start) {
            mp[start->val]++;
            start = start->next;
        }
        
        start = head;
        while(head) {
            if(mp[head->val] == 1){
                start = head; 
                break;
            }
            head = head->next;
        }
        
        if(!head) return nullptr;
        
        ListNode* temp = start;
        while(temp && temp->next) {
            if(mp[temp->next->val] != 1)
                temp->next = temp->next->next;
            else temp = temp->next;
        }
        
        return start;
    }
};

// [1,2,3,3,4,4,5]
// [1,1,1,2,3]
// [1,2,2]
// [1,1]
// [1]