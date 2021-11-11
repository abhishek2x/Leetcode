class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n];
        
        for(int i=n-1; i>=0; i--) {
            if(i == n-1 || i == n-2) dp[i] = cost[i]; 
            else dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
        }
        
        return min(dp[0], dp[1]);
    }
};