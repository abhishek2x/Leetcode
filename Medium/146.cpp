class Solution {
public:
    int minimumTotal(vector<vector<int>>& v) {
        int dp[201][201];
        dp[0][0] = v[0][0];
        
        int n = v.size()-1;
        
        for(int i=1; i<=n; i++) {
            for(int j=0; j<v[i].size(); j++) {
                if(j == 0) 
                    dp[i][j] = v[i][j] + dp[i-1][j];
                else if(j == v[i].size()-1) 
                    dp[i][j] = v[i][j] + dp[i-1][j-1];
                else 
                    dp[i][j] = v[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
            }
        }
        
        int res=INT_MAX;
        for(int i=0; i<=n; i++) {
            int num=dp[n][i];
            if(num<res) res = num;
        }
        return res;
    }
};