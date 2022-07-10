class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;
        
        vector<int> prev(n, 0);
        
        for(int i=0; i<m; i++) {
            vector<int> curr(n, 0);
            for(int j=0; j<n; j++) {
                if(!i and !j) curr[j] = 1;
                else if(obstacleGrid[i][j] == 1) curr[j] = 0;
                else {
                    int up = 0, left = 0;
                    if(i) up = prev[j];
                    if(j) left = curr[j-1];
                    
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};

/*
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;
        
        vector<vector<int>> dp(m, vector<int> (n, 0));
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!i and !j) dp[i][j] = 1;
                else if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else {
                    int up = 0, left = 0;
                    if(i) up = dp[i-1][j];
                    if(j) left = dp[i][j-1];
                    
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};

*/