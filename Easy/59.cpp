class Solution {
public:
    vector<vector<int>> generate(int n) {
        int dp[n][n];
        memset(dp, -1, sizeof(dp));
        
        vector<vector<int>> v(n);
        
        // initialisation
        for(int i=0; i<n; i++) 
            for(int j=0; j<=i; j++) 
                if(i == 0 || j==0 || i == j) dp[i][j] = 1;
        
        // dp work
        for(int i=1; i<n; i++) 
            for(int j=1; j<i; j++) 
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        
        // copy
        for(int i=0; i<n; i++) {
            for(int j=0; j<=i; j++) 
                v[i].push_back(dp[i][j]);
        }
        return v;
    }
};