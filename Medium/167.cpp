class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int r = board.size();
        int c = board[0].size();
        vector<vector<int>> temp(r, vector<int>(c));
        
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                int neighbours = 0;
                if(i>0 and board[i-1][j]) neighbours++;
                if(j>0 and board[i][j-1]) neighbours++;
                if(i<r-1 and board[i+1][j]) neighbours++;
                if(j<c-1 and board[i][j+1]) neighbours++;
                if(i>0 and j>0 and board[i-1][j-1]) neighbours++;
                if(i>0 and j<c-1 and board[i-1][j+1]) neighbours++;
                if(i<r-1 and j>0 and board[i+1][j-1]) neighbours++;
                if(i<r-1 and j<c-1 and board[i+1][j+1]) neighbours++;

                if(board[i][j]) {
                    if(neighbours < 2 || neighbours > 3) temp[i][j] = 0;
                    else temp[i][j] = 1;
                }
                else if(!board[i][j]) {
                    if(neighbours == 3) temp[i][j] = 1;
                    else temp[i][j] = 0;
                }
            }
        }
        
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                board[i][j] = temp[i][j];
            }
        }
        
    }
};