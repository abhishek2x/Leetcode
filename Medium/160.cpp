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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        
        stack<ListNode*> st;
        ListNode* temp = head;
        int i = 0, size = 0;
        
        while(temp) {
            st.push(temp);
            size++;
            temp = temp->next;
        }
        
        temp=head;
        while(i<size/2) {
            st.top()->next = temp->next;
            temp->next = st.top();
            temp = temp->next->next;
            
            st.pop();
            i++;
        }
        temp->next = nullptr;
    }
};