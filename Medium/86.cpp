// DFS

class Solution {
public:
    int r, c;
    
    void dfs(vector<vector<int>>& grid, int i, int j, int dist=1) {
        if(min(i, j) < 0 or i >= r or j >= c or (grid[i][j] != 0 && grid[i][j] <= dist)) return;
        
        grid[i][j] = dist;
        
        dfs(grid, i+1, j, dist+1);
        dfs(grid, i-1, j, dist+1);
        dfs(grid, i, j+1, dist+1);
        dfs(grid, i, j-1, dist+1);
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    dfs(grid, i, j);
                }
            }
        }
        
        int ans = -1;
        for(int i=0; i<r; i++) 
            for(int j=0; j<c; j++) if(grid[i][j] > 1) ans = max(ans, grid[i][j]-1);
        
        return ans;
    }
};