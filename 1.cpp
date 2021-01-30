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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* output = head;
        
        int carry=0;
        
        while(l1 || l2){
            int data = carry + (l1?l1->val:0) + (l2?l2->val:0);
            carry = data/10;
            output->next = new ListNode(data%10);
            
            // move the pointer
            output = output->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        
        if(carry == 1 ) {
            output->next = new ListNode(1);
        }
        return head->next;
    }
};

// ----------------recursion - py---------

// # Definition for singly-linked list.

// class ListNode(object):
//     def __init__(self, x):
//         self.val = x
//         self.next = None

        
// def printList(nodeStart):
//     print(nodeStart.val)
//     if nodeStart.next == None:
//         return
//     else:
//         printList(nodeStart.next)

// class Solution(object):
//     def addTwoNumbers(self, l1, l2):
            
//         if l1 == None:
//             return l2
            
//         if l2 == None:
//             return l1
            
//         sval = l1.val + l2.val
//         if sval < 10:
//             ansNode = ListNode(sval)
//             ansNode.next = self.addTwoNumbers(l1.next, l2.next)
//             return ansNode
//         else:
//             rval = l1.val + l2.val-10
//             ansNode = ListNode(rval)
//             ansNode.next = self.addTwoNumbers(ListNode(1), self.addTwoNumbers(l1.next, l2.next))
//             return ansNode
