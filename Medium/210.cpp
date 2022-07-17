class Solution {
public:
    
    int mod = 1e9 + 7;
    
    // number of ways to take ball out of boundary
    int f(int i, int j, int maxMoves, int moves, int m, int n, vector<vector<vector<int>>> &dp) {
        if(min(i, j) < 0 || i > m-1 || j > n-1) return 1;
        
        if(moves == maxMoves) return 0;
        
        if(dp[moves][i][j] != -1) return dp[moves][i][j];
        
        int tempVal = 0;
        tempVal = (tempVal + f(i+1, j, maxMoves, moves+1, m, n, dp)) % mod;
        tempVal = (tempVal + f(i-1, j, maxMoves, moves+1, m, n, dp)) % mod;
        tempVal = (tempVal + f(i, j+1, maxMoves, moves+1, m, n, dp)) % mod;
        tempVal = (tempVal + f(i, j-1, maxMoves, moves+1, m, n, dp)) % mod;
        
        return dp[moves][i][j] = tempVal;
    }
    
    int findPaths(int m, int n, int maxMove, int i, int j) {
        // dp[moves][i][j]
        vector<vector<vector<int>>> dp(maxMove, vector<vector<int>> (m, vector<int> (n, -1)));
        return f(i, j, maxMove, 0, m, n, dp);
    }
};