class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int r = grid.size();
        int c = grid[0].size();
        int fresh=0;
        queue<pair<int, int>> q;
        
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    fresh++;
        
        if(fresh == 0) return 0;
        
        int ans=0;
        int X[4] = {0, 0, -1, +1};
        int Y[4] = {-1, +1, 0, 0};
        
        while(!q.empty()) {
            int size = q.size();
            ans++;
            
            for(int i=0; i<size; i++) {
                int a = q.front().first;
                int b = q.front().second;
                q.pop();
                
                for(int k=0; k<4; k++) {
                    int x = a + X[k];
                    int y = b + Y[k];
                    
                    if(min(x, y) >= 0 && x<r && y<c && grid[x][y] == 1){
                        grid[x][y] = 2;
                        q.push({x, y});
                        fresh--;
                    }
                }
            }
        }
        
        return fresh == 0 ? ans-1 : -1;
    }
};