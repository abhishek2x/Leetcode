// DFS

class Solution {
    const int MAX_MATRIX_SIZE = 10000; // as in problem statement
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
        {
            for(int r = 0; r < matrix.size(); ++r)
                for(int c = 0; c < matrix[0].size(); ++c)
                    if(matrix[r][c] == 1) matrix[r][c] = MAX_MATRIX_SIZE;

            for(int r = 0; r < matrix.size(); ++r)
                for(int c = 0; c < matrix[0].size(); ++c)
                    get_distance(r, c, matrix);
            return matrix;
        }

    protected:
        int get_distance(int r, int c,  vector<vector<int>>& matrix)
        {
            if(r >= matrix.size() || r < 0 || c >= matrix[0].size() || c < 0 || matrix[r][c] == -2) return MAX_MATRIX_SIZE;
            
            if(matrix[r][c] == 0 || matrix[r][c] == 1) return matrix[r][c]; // 1 is min distance - no need to compute further

            int dist =  matrix[r][c];
            matrix[r][c] = -2; // -2 = do not go here again.
            
            dist = min(dist, get_distance(r+1, c, matrix)+1);
            dist = min(dist, get_distance(r-1, c, matrix)+1);
            dist = min(dist, get_distance(r, c+1, matrix)+1);
            dist = min(dist, get_distance(r, c-1, matrix)+1);
            
            matrix[r][c] = dist;
            return dist;
        }
};
