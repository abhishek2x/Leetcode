#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();        
        if(n == 1) return 0;

        vector<int> l(n), h(n);
        l[0] = nums[0];
        h[n-1] = nums[n-1];
        
        for(int i=1; i<n; i++) l[i] = nums[i] + l[i-1];
        for(int i=n-2; i>=0; i--) h[i] = nums[i] + h[i+1];

        int mIdx=-1;
        for(int i=0; i<n; i++)
            if(l[i] == h[i]) {mIdx = i; break;}

        return mIdx;
    }
};