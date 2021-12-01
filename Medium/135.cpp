class Solution {
public:
    vector<int> dp;
    
    int worker(vector<int>& nums, int i) {
        if(i >= size(nums)) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(worker(nums, i+1), nums[i] + worker(nums, i+2));
    }
    
    int rob(vector<int>& nums) {
        dp.resize(size(nums), -1);
        return worker(nums, 0);
    }
};