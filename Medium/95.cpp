class Solution {
public:
    int r, c, peri;
    
    bool isValid(int i, int j) {
        return min(i, j) >= 0 && i < r && j < c;
    }
    
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        if(!isValid(i, j) or vis[i][j] == 1 or grid[i][j] != 1) return;
        
        vis[i][j] = 1;        
        
        if(!isValid(i+1, j)) peri++;
        else if(grid[i+1][j] == 0) peri++;

        if(!isValid(i-1, j)) peri++;
        else if(grid[i-1][j] == 0) peri++;

        if(!isValid(i, j+1)) peri++;
        else if(grid[i][j+1] == 0) peri++;

        if(!isValid(i, j-1)) peri++;
        else if(grid[i][j-1] == 0) peri++;
                
        dfs(i+1, j, grid, vis);
        dfs(i-1, j, grid, vis);
        dfs(i, j+1, grid, vis);
        dfs(i, j-1, grid, vis);
        
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        
        r = grid.size();
        c = grid[0].size();
        vector<vector<int>> vis(r, vector<int>(c, 0));
        peri = 0;
        
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                dfs(i, j, grid, vis);
        
        return peri;
    }
};