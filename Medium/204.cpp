class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> prev(n, 0);
        for(int j=0; j<n; j++) prev[j] = matrix[0][j];

        for(int i=1; i<m; i++) {
            vector<int> curr(n, 0);
            for(int j=0; j<n; j++) {
                int u = matrix[i][j] + prev[j];
                
                int ul = matrix[i][j];
                if(j>0) ul += prev[j-1];
                else ul = 10e5;
                
                int ur = matrix[i][j];
                if(j<n-1) ur += prev[j+1];
                else ur = 10e5;
                
                
                curr[j] = min({ul, u, ur});
            }
            prev = curr;
        }
        
        int mini = *min_element(prev.begin(), prev.end());
        return mini;
    }
};