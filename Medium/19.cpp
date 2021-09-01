#include <bits/stdc++.h>
using namespace std;
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        ListNode* temp = head;
        while(temp) {
            size++;
            temp = temp->next;
        }
        
        if(size == 1 && n == 1) {
            return NULL;
        }
        cout << size << " " << size-n << "\n";
        int pos = size - n;
        
        if(pos == 0) {
            ListNode* t = head->next; return t;
        }
        temp = head;

        for(int i=0; i<pos-1; i++) {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        return head;
    }
};