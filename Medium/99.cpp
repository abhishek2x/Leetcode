class Solution {
public:
    int r, c;

    bool checkifFound(int i, int j, vector<vector<char>>& board, string word, int index) {
        
        if(index == word.size()) return true;
        if(min(i, j) < 0 or i>=r or j>=c or board[i][j] != word[index]) return false;
        
        char temp = board[i][j];
        board[i][j] = '0';
        
        if(checkifFound(i+1, j, board, word, index+1) || 
           checkifFound(i-1, j, board, word, index+1) || 
           checkifFound(i, j+1, board, word, index+1) || 
           checkifFound(i, j-1, board, word, index+1)) 
            return true;
        
        board[i][j] = temp;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        r = board.size();
        c = board[0].size();

        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                if(board[i][j] == word[0])
                    if(checkifFound(i, j, board, word, 0))
                        return true;
        
        return false;
    }
};