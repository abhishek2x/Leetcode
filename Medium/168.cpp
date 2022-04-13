class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n));
        int ele = 1;
        
        for(int i=0; i<=n/2; i++) {
            for(int top=i; top<=n-i-1; top++) {
                v[i][top] = ele++;
            }
            for(int right=i+1; right<=n-i-1; right++){
                v[right][n-1-i] = ele++;
            }
            for(int down=n-2-i; down>=0+i; down--) {
                v[n-i-1][down] = ele++;
            }
            for(int left=n-2-i; left>=1+i; left--){
                v[left][i] = ele++;
            }
        }
        
        return v;
    }
};