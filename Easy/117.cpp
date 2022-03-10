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
    
    int lengthOfList(ListNode *A) {
        int ans=0;
        while(A && A->next) {
            ans++;
            A = A->next;
        }
        return ans;
    }
    
    ListNode *NodeAfterDis(ListNode* A, int dis, ListNode* B) {
        while(dis>0) {A = A->next; dis--;}
        
        while(A != B) {
            A = A->next;
            B = B->next;
        }
        
        return B;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = lengthOfList(headA);
        int lenB = lengthOfList(headB);
        
        if(lenA > lenB) {
            return NodeAfterDis(headA, lenA-lenB, headB);
        } else {
            return NodeAfterDis(headB, lenB-lenA, headA);
        }
    }
};