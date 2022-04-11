class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<int> v;
        
        for(auto i: grid) {
            for(auto j: i) {
                v.push_back(j);
            }
        }
        // cyclic rotate v by k
        
        k = k % v.size();
        
        // copy last k
        vector<int> lastK;
        for(int i = v.size()-k; i < v.size(); i++) 
            lastK.push_back(v[i]);
        
        // shift elements
        for(int i=v.size()-k-1; i>=0; i--) 
            v[k+i] = v[i];
        
        // paste first k
        for(int i=0; i<k; i++) {
            v[i] = lastK[i];
        }
        
        int index=0;
        for(int i=0; i<m; i++) 
            for(int j=0; j<n; j++) 
                grid[i][j] = v[index++];
        
        return grid;
    }
};