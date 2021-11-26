class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX-5);
        dp[0] = 0;
        
        for(int i=0; i<coins.size(); i++) {
            for(int j=coins[i]; j<dp.size(); j++) {
                dp[j] = min(dp[j], dp[j-coins[i]]+1);
            }
        }
        
        return dp[amount] != INT_MAX-5 ? dp[amount] : -1;
    }
};