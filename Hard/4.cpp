class Solution {
public:
    int r, c;
    
    bool isPresent(string str, int i, int j, vector<vector<char>>& board, int idx) {
        
        if(idx == str.length()) return true;
        if(min(i, j) < 0 or i == r or j == c or board[i][j] != str[idx]) return false;
        
        char temp = board[i][j];
        board[i][j] = '&';
        
        if (isPresent(str, i+1, j, board, idx+1) || 
            isPresent(str, i-1, j, board, idx+1) || 
            isPresent(str, i, j+1, board, idx+1) || 
            isPresent(str, i, j-1, board, idx+1)) {
                board[i][j] = temp;
                return true;
        }
        
        board[i][j] = temp;
        return false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        r = board.size();
        c = board[0].size();
       
        for(string str: words) {
            for(int i=0; i<r; i++) {
                for(int j=0; j<c; j++) {
                    if(board[i][j] == str[0]) {
                        if(isPresent(str, i, j, board, 0)){
                            cout << str << " ";
                            res.push_back(str);
                        }
                    }
                }
            }
        }
        
        return res;
    }
};