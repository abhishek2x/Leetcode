/*!
* Copyright (c) 2020 Abhishek Srivastava
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve() {
    string str; cin >> str;
    int len = str.length();
    if(len <= 2)  {
        cout << "Valid\n"; return;
    }

    char lastChar = str[0];
    int count = 1;

    for(int i=1; i<len; i++) {
        if(str[i] == lastChar) count++;
        else {
            count = 1;
            lastChar = str[i];
        }

        // condition
        if(count > 2) {
            cout << "Invalid\n"; return;
        }
    }
    cout << "Valid\n";
}

int main(){

    ios :: sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}