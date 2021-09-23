class Solution {
public:
    int r, c;
    
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if(min(i, j) < 0 or i >= r or j >= c or grid[i][j] == 0) return 0;
        
        grid[i][j] = 0;
        
        return 1 + dfs(grid, i+1, j) + dfs(grid, i-1, j) + dfs(grid, i, j+1) + dfs(grid, i, j-1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        
        int ans=0;
        
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                if(grid[i][j] == 1) 
                    ans = max(ans, dfs(grid, i, j));
        
        return ans;
    }
};