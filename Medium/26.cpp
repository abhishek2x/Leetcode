#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> v;
        
        for(int i=0; i<n; i++) {
            int csum=0;
            for(int j=i; j<n; j++) {
                csum += nums[j];
                v.push_back(csum);
            }
        }

        sort(v.begin(), v.end());

        int ans=0;
        for(int i=left-1; i<=right-1; i++) ans = (ans+v[i])%(1000000007);
        return ans;
    }
};