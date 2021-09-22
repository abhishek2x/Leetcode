class Solution {
public:
    
    void DFS(vector<vector<int>>& grid, int i, int j, int row, int col, char ch) {
        // modifying values in grid
        if(i<0 or j<0 or i>row-1 or j>col-1 or grid[i][j] != 1) return;
        
        grid[i][j] = ch;
        
        DFS(grid, i-1, j, row, col, ch);
        DFS(grid, i, j-1, row, col, ch);
        DFS(grid, i+1, j, row, col, ch);
        DFS(grid, i, j+1, row, col, ch);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        if(!row) return 0;
        
        int col = grid[0].size();
        
        // traverse for first and last col.
        for(int i=0; i<row; i++) {
            if(grid[i][col-1] == 1) 
                DFS(grid, i, col-1, row, col, -1);
            if(grid[i][0] == 1) 
                DFS(grid, i, 0, row, col, -1);
        }      
        
        // traverse for first and last row.
        for(int i=0; i<col; i++) {
            if(grid[row-1][i] == 1) 
                DFS(grid, row-1, i, row, col, -1);
            if(grid[0][i] == 1) 
                DFS(grid, 0, i, row, col, -1);
        }
        
        int ans = 0;
        // final iterate
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++) 
                if(grid[i][j] == 1) ans++;
        
        return ans;
    }
};