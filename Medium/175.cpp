// Helper file for pointers guide

/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void passByPointer(int *p, int *q) {
    cout << *p << " " << *q << "\n";            // 5 6
    cout << p << " " << q << "\n";              // 0x7ffe73854780 0x7ffe73854784
}

void solve() {
    int a = 5;
    int b = 6;

    cout << "a: " << a << "\n";                 // 5
    cout << "b: " << b << "\n";                 // 6
    cout << &a << " " << &b << "\n";            // 0x7ffe73854780 0x7ffe73854784
    int *c, *d;
    c = &a;
    d = &b;
    cout << "PRINTING C AND D: \n\n";
    cout << *c << " " << *d << "\n";            // 5 6
    cout << c << " " << d << "\n";              // 0x7ffe73854780 0x7ffe73854784

    cout << "PRINTING P AND Q: \n\n";
    passByPointer(&a, &b);

    cout << "a: " << a << "\n";
    cout << "b: " << b << "\n";
}

int main(){

    ios :: sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    while(t--)
        solve();

    return 0;
}