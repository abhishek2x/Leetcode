#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {

        int N = nums.size();
        vector<int> leftMax(N);
        vector<int> rightMin(N);
        
        // Preprocessing
        leftMax[0] = nums[0];
        for(int i=1; i<N; i++) 
            leftMax[i] = max(leftMax[i-1], nums[i]);
        
        rightMin[N-1] = nums[N-1];
        for(int i=N-2; i>=0; i--) 
            rightMin[i] = min(rightMin[i+1], nums[i]);
        
        int ans=0;
        for(int i=1; i<N-1; i++) {
            // Main work
            if(nums[i] > leftMax[i-1] && nums[i] < rightMin[i+1])
                ans += 2;
            else if(nums[i-1] < nums[i] && nums[i] < nums[i+1])
                ans += 1;
        }
        return ans;
    }
};