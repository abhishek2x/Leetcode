class Solution {
public:
    int getMaximumGenerated(int n) {
        int dp[n+1];
        int res=INT_MIN;
        
        for(int i=0; i<=n; i++) {
            if(i == 0) dp[0] = 0;
            if(i == 1) dp[1] = 1;
            
            if(i%2 == 0) dp[i] = dp[i/2];
            else dp[i] = dp[i/2] + dp[i/2+1];
            
            res = max(res, dp[i]);
        }
        return res;
    }
};