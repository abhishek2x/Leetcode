class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        vector<vector<int>> dp(r, vector<int> (c, grid[0][0]));
        
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(i == 0 and j == 0) dp[i][j] = grid[0][0];
                else if(i == 0) dp[i][j] = grid[i][j] + dp[i][j-1];
                else if(j == 0) dp[i][j] = grid[i][j] + dp[i-1][j]; 
                else dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[r-1][c-1];
    }
};