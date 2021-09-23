class Solution {
public:
    int r, c;
    
    void dfs(vector<vector<int>>& image, int i, int j, int c1, int c2) {
        if(min(i, j) < 0 or i >= r or  j >= c or image[i][j] != c1) return;
        
        image[i][j] = c2;
        
        // four directions
        dfs(image, i+1, j, c1, c2);
        dfs(image, i-1, j, c1, c2);
        dfs(image, i, j+1, c1, c2);
        dfs(image, i, j-1, c1, c2);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        r = image.size();
        c = image[0].size();
        
        if(image[sr][sc] != newColor) dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};