class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> lastRow(n, 0);
        
        for(int i=n-1; i>=0; i--) {
            vector<int> currRow(n, 0);
            for(int j=i; j>=0; j--) {
                if(i == n-1) {
                    currRow[j] = triangle[i][j];
                }
                else {
                    int up = triangle[i][j] + lastRow[j];
                    int diag = triangle[i][j] + lastRow[j+1];    
                    
                    currRow[j] = min(up, diag);
                }
            }
            lastRow = currRow;
        }
        
        return lastRow[0];
    }
};