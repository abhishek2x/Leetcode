class Solution {
public:
    int ans, r, c;
    
    void do_backtrack(int i, int j, vector<vector<int>>& grid, int cellsToVisit) {
        if(min(i, j) < 0 || i>=size(grid) || j>=size(grid[0]) || grid[i][j] == -1 || grid[i][j] == 3) return;
        
        if(grid[i][j] == 2) {
            if(cellsToVisit == 0) ans++; 
            return;
        }
        
        grid[i][j] = 3; // visited
        int dir[5] = {0, 1, 0, -1, 0};
        
        for(int l=0; l<4; l++) 
            do_backtrack(i+dir[l], j+dir[l+1], grid, cellsToVisit-1);
        
        grid[i][j] = 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        ans=0;
        r = grid.size(); c = grid[0].size();
        
        int x, y, cellsToVisit=0;
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                if(grid[i][j] == 1) 
                    x=i, y=j;
                else if(grid[i][j] != -1) 
                    cellsToVisit++;
        
        do_backtrack(x, y, grid, cellsToVisit);
        return ans;
    }
};