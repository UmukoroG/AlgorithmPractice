class Solution {
public:
   int ROWS;
   int COLS;
   set<pair<int,int>> path;
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();

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
        
        if(rows < 0 || cols<0 || rows>=ROWS || cols>=COLS || 
            board[rows][cols]!=word[i] || path.count({rows,cols})){
            return false;
        }
        path.insert({rows,cols});//insert path once we visit it
        bool res = dfs(board,word,rows+1, cols,i+1)||
                    dfs(board,word,rows-1, cols,i+1)||
                    dfs(board,word,rows, cols+1,i+1)||
                    dfs(board,word,rows, cols-1,i+1);
                    
        path.erase({rows,cols}); //remove path to redo backtracking

        return res;
    }
};