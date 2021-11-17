class Solution {
public:
    int dp[101][101];
    
    int worker(int i, int j, int m, int n) {
        if(min(i, j) < 0 or i>=m or j>=n) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(i == m-1 && j == n-1) return 1;
        
        int ans = 0;
        ans += worker(i+1, j, m, n);
        ans += worker(i, j+1, m, n);
        
        return dp[i][j] = ans;
    }
    
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return worker(0, 0, n, m);
    }
    
};