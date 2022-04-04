class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {        
        int size=0;
        ListNode *temp = head, *node1, *node2;
        
        while(temp) {
            size++;
            temp = temp->next;
        }
        
        int k1 = size-k+1;
        temp = head;
        int index=0;
        
        while(temp) {            
            index++;
            if(index == k) node1 = temp;
            if(index == k1) node2 = temp;

            temp = temp->next;
        }
        
        swap(node1->val, node2->val);
        return head;
        
    }
};