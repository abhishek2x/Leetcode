

/* 

! => [0,0,1,1,0,1,0,0,1,0]
! => [1,1,0,1,1,0,1,1,1,0]
! => [1,0,1,1,1,0,0,1,1,0]
! => [0,1,1,0,0,0,0,1,0,1]
! => [0,0,0,0,0,0,1,1,1,0]
! => [0,1,0,1,0,1,0,1,1,1]
! => [1,0,1,0,1,1,0,0,0,1]
! => [1,1,1,1,1,1,0,0,0,0]
! => [1,1,1,0,0,1,0,1,0,1]
! => [1,1,1,0,1,1,0,1,1,0]

*/
// Flood Fill approach
 
class Solution {
public:
    int m, n;
    
    void dfs_fill(vector<vector<int>>& grid, int i, int j) {
        if(min(i, j) < 0 or i >= m or j >= n or grid[i][j]) return;
        
        grid[i][j] = 1;
        
        dfs_fill(grid, i+1, j);
        dfs_fill(grid, i-1, j);
        dfs_fill(grid, i, j+1);
        dfs_fill(grid, i, j-1);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        
        // row
        for(int i=0; i<m; i++) 
            dfs_fill(grid, 0, i), dfs_fill(grid, m-1, i);
        
        // col
        for(int i=0; i<m; i++) 
            dfs_fill(grid, i, 0), dfs_fill(grid, i, n-1);
        
        
        // counts 0's
        int res=0;
        for(int i=1; i<m-1; i++) 
            for(int j=1; j<n-1; j++) 
                if(grid[i][j] == 0) 
                    dfs_fill(grid, i, j), res++;
        
        return res;
    }
};