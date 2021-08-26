class Solution {
public:
    
    int dp[10000][80];
    
    int finder(vector<vector<int>> &mat, int row, int sum, int target) {
        if(row >= mat.size())  return abs(sum-target);
        if(dp[sum][row] != -1) return dp[sum][row];
        
        int ans=INT_MAX;
        for(int i=0; i<mat[0].size(); i++)
            ans = min(ans, finder(mat, row+1, sum+mat[row][i], target));
        return dp[sum][row] = ans;
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        memset(dp, -1, sizeof(dp));
        return finder(mat, 0, 0, target);
    }
};