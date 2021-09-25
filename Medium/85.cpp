// BFS

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> dis(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(!mat[i][j]) {
                    dis[i][j] = 0;
                    q.push({i, j});
                }
        
        int xCor[4] = {0, 0, -1, +1};
        int yCor[4] = {+1, -1, 0, 0};
        
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++) {
                int nX = x + xCor[i];
                int nY = y + yCor[i];
                
                // check if valid nX and nY
                if(min(nX, nY) >= 0 and nX < m and nY < n and mat[nX][nY] and dis[nX][nY] == -1) {
                    dis[nX][nY] = dis[x][y] + 1;
                    q.push({nX, nY});
                }
            }
        }
        
        return dis;
    }
};