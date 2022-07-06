#include<bits/stdc++.h>
using namespace std;

class DLL {
public:
    int val;
    DLL* prev;
    DLL* next;
    DLL() {
        val = 0;
        prev = nullptr;
        next = nullptr;
    }
    DLL(int v) {
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};

void print(DLL* head) {
    
    cout << "\n\n";
    DLL* temp = head;

    int i=6;
    while(i--) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "\n\n";
}

void insertNode(DLL* &head, int n) {

    if(n == 0) {
        DLL* newNode = new DLL(-45);
        newNode->prev = head->prev;
        head->prev->next = newNode;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    int i=1;
    DLL* iterator = head;
    while(i < n-1) {
        iterator = iterator->next;
        i++;
    }

    DLL* newNode = new DLL(-45);
    newNode->next = iterator->next;
    iterator->next->prev = newNode;
    iterator->next = newNode;
    newNode->prev = iterator;
}

int main() {
    DLL *head = new DLL(1);
    DLL* temp = head;
    
    for(int i=2; i<=5; i++) {
        DLL* newNode = new DLL(i);
        temp->next = newNode;
        temp->next->prev = temp;
        temp = temp->next;
    }

    temp->next = head;
    head->prev = temp;

    print(head);
    insertNode(head, 3);
    print(head);

}