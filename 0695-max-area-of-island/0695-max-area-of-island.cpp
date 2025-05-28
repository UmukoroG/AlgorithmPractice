class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()==true){
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        
        int result = 0;
        
        for (int i = 0; i < m; i++) {//rows
            for (int j = 0; j < n; j++) {//cols
                if (grid[i][j] == 1) {
                    int maxA = dfs(grid, i, j, m, n);
                    result=max(maxA, result);
                }
            }
        }
        
        return result;
    }

private:
    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = 0;//visited
        
        int count = 1;
        //visit all direction for each cell to find 
        count+= dfs(grid, i - 1, j, m, n);
        count+= dfs(grid, i + 1, j, m, n);
        count+= dfs(grid, i, j - 1, m, n);
        count+= dfs(grid, i, j + 1, m, n);
        
        return count;
    }
};
