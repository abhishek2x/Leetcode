#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int ans=-1; int n=height.size();
        int l=0, r=n-1;
        
        while(l<r) {
            ans = max(ans, ((r-l) * min(height[r], height[l])));
            // cout << ans << "->" << r << " " << l << "\n";
            if(height[l] == min(height[r], height[l])) l++;
            else r--;
        }
        return ans;
    }
};