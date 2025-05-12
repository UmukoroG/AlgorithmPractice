class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int ROWS = board.size();
        int COLS = board[0].size();

        for(int rows=0; rows<ROWS; rows++){
            for(int cols=0; cols<COLS; cols++){
                if(dfs(board, word, rows,cols, 0)){
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, string word, int rows, int cols, int i){
        if(i == word.size()) 
            return true; //track we have reached the end of the search
        
        if(rows < 0 || cols<0 || rows>=board.size() || cols>=board[0].size() || 
            board[rows][cols]!=word[i]){
            return false;
        }
        char temp = board[rows][cols];
        board[rows][cols]='#'; //marked as visited

        //visits all required paths
        bool res = dfs(board,word,rows+1, cols,i+1)||
                    dfs(board,word,rows-1, cols,i+1)||
                    dfs(board,word,rows, cols+1,i+1)||
                    dfs(board,word,rows, cols-1,i+1);
                    
        board[rows][cols]=temp; //restore the original value;

        return res;
    }
};