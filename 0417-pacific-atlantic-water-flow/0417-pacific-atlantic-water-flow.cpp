class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows= heights.size();
        int cols=heights[0].size();

        vector<vector<int>> res;

        set<pair<int, int>> pac;
        set<pair<int,int>>atl;

        for(int i=0; i<cols; i++){
            dfs(0, i, rows, cols, pac, heights[0][i], heights);
            dfs(rows-1, i, rows,cols, atl, heights[rows-1][i], heights);
        }

        for(int i=0; i<rows; i++){
            dfs(i, 0, rows, cols, pac, heights[i][0], heights);
            dfs(i, cols-1, rows, cols, atl, heights[i][cols-1], heights);
        }

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(pac.find({r,c})!=pac.end() && atl.find({r,c})!=atl.end()){
                    res.push_back({r,c});
                }
            }
        }
        return res;
    }
private:
    void dfs(int r, int c, int rows, int cols, set<pair<int,int>>& visit, int prevHeight, vector<vector<int>>& heights){
            if(visit.find({r,c})!=visit.end() || r<0 || c<0 || r == rows || c == cols || heights[r][c] < prevHeight){
               return;         
            }

            visit.insert({r,c});

            dfs(r+1, c, rows, cols, visit, heights[r][c], heights);
            dfs(r-1, c, rows, cols, visit, heights[r][c], heights);
            dfs(r, c+1, rows, cols, visit, heights[r][c], heights);
            dfs(r, c-1, rows, cols, visit, heights[r][c], heights);

    }
};