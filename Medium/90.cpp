// You are using GCC

#include <bits/stdc++.h>
using namespace std;

int main () {
    int L, B;
    cin >> L >> B;
    
    int l1, b1, l2, b2;
    cin >> l1 >> b1 >> l2 >> b2;
    
    if(l1>L || l2>L || b1>B || b2>B) {
        cout << "Leonardo cannot fix both painting";
    }
    else if(l1+l2 > L && b1 + b2 > B) {
        cout << "Leonardo cannot fix both painting";
    }
    else {
        int a1 = l1*b1;
        int a2 = l2*b2;
        int A = L*B;
        
        if(A < a1+a2) cout << "Leonardo cannot fix both painting";
        else cout << "Leonardo can fix both painting";
    }
}