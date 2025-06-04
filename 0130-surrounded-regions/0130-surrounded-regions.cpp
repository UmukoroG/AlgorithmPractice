class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        if(rows == 0) return;

        // Start DFS from all 'O's on the border
        for (int r = 0; r < rows; r++) {
            if (board[r][0] == 'O') dfs(board, rows, cols, r, 0);
            if (board[r][cols - 1] == 'O') dfs(board, rows, cols, r, cols - 1);
        }
        for (int c = 0; c < cols; c++) {
            if (board[0][c] == 'O') dfs(board, rows, cols, 0, c);
            if (board[rows - 1][c] == 'O') dfs(board, rows, cols, rows - 1, c);
        }

        //covert remaining 0's to X and '#' and back
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(board[r][c]=='O'){
                    board[r][c]='X';
                }
                else if(board[r][c]=='#'){
                    board[r][c]='O';
                }
            }
        }
    }
private:
    void dfs(vector<vector<char>>& board, int rows, int cols, int i, int j){
        if(i<0 || i>=rows || j<0 || j>=cols || board[i][j]!='O'){
            return;
        }

        board[i][j]='#'; //mark as safe

        dfs(board, rows, cols, i-1, j);
        dfs(board, rows, cols, i+1, j);
        dfs(board, rows, cols, i, j-1);
        dfs(board, rows, cols, i, j+1);

    }
};