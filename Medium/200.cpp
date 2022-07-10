class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);
        
        for(int i=0; i<m; i++) {
            vector<int> curr(n, 0);
            for(int j=0; j<n; j++) {
                if(!i && !j) curr[j] = 1;
                else {
                    int right = 0, up = 0;
                    if(i) up = prev[j];
                    if(j) right = curr[j-1];
                    
                    curr[j] = right + up; 
                }
            }
            prev = curr;
        }
        
        return prev[n-1];
    }
};