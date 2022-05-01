// Unguarded = 0
// Guard = 2
// Wall = -2
// guard covered = 1

class Solution {
public:
    
    int countUnguarded(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w) {
        vector<vector<int>> v(m, vector<int>(n, 0));
        
        for(auto it: g) {
            v[it[0]][it[1]] = 2;
        }
        
        for(auto it: w) {
            v[it[0]][it[1]] = -2;
        }
        
        int k = g.size();
        
         for(int j=0;j<k;j++){
            int x = g[j][0], y = g[j][1];
            for(int i=x-1;i>=0;i--){ // up
                if(v[i][y]==-2 || v[i][y]==2) break;
                v[i][y] = 1;
            }
            for(int i=x+1;i<m;i++){ // down
                if(v[i][y]==-2 || v[i][y]==2) break;
                v[i][y] = 1;
            }
            for(int i=y-1;i>=0;i--){ // left
                if(v[x][i]==-2 || v[x][i]==2) break;
                v[x][i] = 1;
            }
            for(int i=y+1;i<n;i++){ // right
                if(v[x][i]==-2 || v[x][i]==2) break;
                v[x][i] = 1;
            }
        }
        
        int res=0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(v[i][j] == 0) {
                    res++;
                }
            }
        }
        return res;
    }
};