class Solution {
public:
    int r, c;
    
    bool isValid(int i, int j) {
        return min(i, j) >= 0 && i<r && j < c;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        r = grid.size();
        c = grid[0].size();
        
        if(grid[0][0] || grid[r-1][c-1]) return -1;
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};

        while(!q.empty()) {
            int a = q.front().first;
            int b = q.front().second;
            
            if(a == r-1 && b == c-1) return grid[a][b];
            q.pop();
            
            for(auto direction : directions){
                int nx = a + direction[0];
                int ny = b + direction[1];
                if(nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] == 0){
                    q.push(make_pair(nx,ny));
                    grid[nx][ny] = grid[a][b] + 1;
                }
            }
        }
        return -1;
    }
};