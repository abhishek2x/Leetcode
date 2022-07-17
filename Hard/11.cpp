class Solution {
public:
    int n, m;
    
    int f(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp) {
        if(j1 < 0 || j2 < 0 || j1 > m-1 || j2 > m-1) 
            return -1e8;
        
        if(i == n-1) {
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2]; 
        }
        
        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int maxi = -1e8;
        
        for(int dj1 = -1; dj1 <= +1; dj1++) {
            for(int dj2 = -1; dj2 <= +1; dj2++) {
                int value;
                if(j2 == j1) 
                    value = grid[i][j1];
                else 
                    value = grid[i][j1] + grid[i][j2];
                
                value += f(i+1, j1+dj1, j2+dj2, grid, dp);
                maxi = max(maxi, value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        // nxmxm
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1)));
        
        return f(0, 0, m-1, grid, dp);
    }
};