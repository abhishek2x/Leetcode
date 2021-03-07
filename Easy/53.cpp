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
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> nodeStack; 		
        ListNode* pHead = head;
        
        while (pHead) {
            nodeStack.push(pHead);
            pHead = pHead->next;
        }
        
        while(head) {
            if(head->val != nodeStack.top()->val)
                return false;
            nodeStack.pop();
            head=head->next;
        }
        return true;
    }
};
