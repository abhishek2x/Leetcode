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




class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size());
        
        if(nums.size() == 1) return nums[0];
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i=2; i<nums.size(); i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        
        return dp[nums.size()-1];
    }
};