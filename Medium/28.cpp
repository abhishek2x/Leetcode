#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        vector<int> v;

        int r = a.size();
        int c = a[0].size();

        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                v.push_back(a[i][j]);

        sort(v.begin(), v.end());
        return v[k-1];
    }
};