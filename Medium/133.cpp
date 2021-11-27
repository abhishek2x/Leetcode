class Solution {
public:
    
    bool subsetSum(vector<int>& nums, int n, int target) {
        int dp[n+1][target+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=target; j++) {
                if(i == 0 && j == 0) dp[i][j] = 1;
                else if(i == 0) dp[i][j] = 0;
                else if(j == 0) dp[i][j] = 1;
                else if(dp[i-1][j] == 1) dp[i][j] = 1;
                else {
                    if(nums[i-1] > j)
                        dp[i][j] = dp[i - 1][j];
                    else 
                        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }        
        return dp[n][target];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0, tar=0;
        for(int ele: nums) sum += ele;
        
        if(sum%2) return false;
        
        return subsetSum(nums, nums.size(), sum/2);
    }
};