class Solution {
public:
    
    // Convert it into Island Question
    
    
    int dfs(vector<vector<int>> &island, int i, int j, int size) {
        if(min(i, j) < 0 || max(i, j) > size-1 || island[i][j] != 0)
            return 0;
        
        island[i][j] = 1;
        
        return 1 + dfs(island, i+1, j, size) + dfs(island, i, j+1, size) + dfs(island, i-1, j, size) + dfs(island, i, j-1, size);
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> island(n*3, vector<int>(n*3, 0));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '/')
                    island[i*3][j*3 + 2] = island[i*3 + 1][j*3 + 1] = island[i*3 + 2][j*3] = 1;
                else if(grid[i][j] == '\\') 
                    island[i*3][j*3] = island[i*3 + 1][j*3 + 1] = island[i*3 + 2][j*3 + 2] = 1;
            }
        }
        
        int regions=0;
        
        for(int i=0; i<n*3; i++) {
            for(int j=0; j<n*3; j++) {
                regions += dfs(island, i, j, n*3) ? 1 : 0;
            }
        }
        return regions;
    }
};