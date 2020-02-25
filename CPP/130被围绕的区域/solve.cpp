class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0)
            return;
        int row = board.size();
        int column = board[0].size();
        for(int i = 0; i < row; ++i) {
            if(board[i][0] == 'O')
                dfs(board, i, 0);
            if(board[i][column - 1] == 'O')
                dfs(board, i, column - 1);
        }

        for(int i = 0; i < column; ++i) {
            if(board[0][i] == 'O')
                dfs(board, 0, i);
            if(board[row - 1][i] == 'O')
                dfs(board, row - 1, i);
        }
        for(int i = 0; i < row; ++i) {
            for(char& ch : board[i]) {
                if(ch == 'O')
                    ch = 'X';
                else if(ch == 'E')
                    ch = 'O';
            }
        }
    }
private:
    void dfs(vector<vector<char>>& board, int i, int j) {
        if(i < 0 || i >= board.size())
            return;
        if(j < 0 || j >= board[0].size())
            return;
        if(board[i][j] == 'O') {
            board[i][j] = 'E';
            dfs(board, i - 1, j);
            dfs(board, i, j - 1);
            dfs(board, i + 1, j);
            dfs(board, i, j + 1);
        }
    }
};