class Solution {
public:
    
    void do_dfs(int i, int j, int r, int c, vector<vector<char>>& board, char to) {
        if(min(i, j) < 0 || i > r-1 || j > c-1)
            return;
        
        if(board[i][j] == 'O')
        board[i][j] = to;
        
        do_dfs(i+1, j, r, c, board, to);
        do_dfs(i-1, j, r, c, board, to);
        do_dfs(i, j+1, r, c, board, to);
        do_dfs(i, j-1, r, c, board, to);
    }
    
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        for(int i=0; i<m; i++) 
            for(int j=0; j<n; j++) 
                if((i == 0 || j == 0 || i == m-1 || j == n-1) && board[i][j] == 'O') 
                    do_dfs(i, j, m, n, board, '$');

        for(int i=0; i<m; i++) 
            for(int j=0; j<n; j++) 
                if((i == 0 || j == 0 || i == m-1 || j == n-1) && board[i][j] == 'O') 
                    do_dfs(i, j, m, n, board, 'X');

        for(int i=0; i<m; i++) 
            for(int j=0; j<n; j++) 
                if((i == 0 || j == 0 || i == m-1 || j == n-1) && board[i][j] == 'O') 
                    do_dfs(i, j, m, n, board, 'O');
    }
    
};