class Solution {
public:
    int r, c;
    
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(min(i, j) < 0 or i > r or j > c or grid[i][j] == '0' or grid[i][j] == 'V') return;
        
        grid[i][j] = 'V';
        
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
     }
    
    int numIslands(vector<vector<char>>& grid) {
        r = grid.size();
        c = grid[0].size();
        
        vector<vector<bool>>visited(m, vector<bool>(n, false));

        
        int res=0;
        for(int i=0; i<r; i++) 
            for(int j=0; j<c; j++) 
                if(grid[i][j] == '1')
                    dfs(grid, i, j), res++;
        
        return res;
    }
};