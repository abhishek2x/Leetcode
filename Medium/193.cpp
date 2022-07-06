#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> r1 = {1, 2};
    vector<int> r2 = {3, 4, 5, 6};
    vector<int> r3 = {0, 1, 2, 3};
    vector<int> r4 = {3, 2, 1};

    vector<vector<int>> arr = {r1, r2, r3, r3};

    for(int i=0; i<4; i++) {
        for(int j=0; j<size(arr[i]); j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}