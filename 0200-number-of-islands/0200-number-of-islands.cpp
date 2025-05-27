class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()==true){
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        
        int result = 0;
        
        for (int i = 0; i < m; i++) {//rows
            for (int j = 0; j < n; j++) {//cols
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, m, n);
                    result++;
                }
            }
        }
        
        return result;
    }
private:
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';//visited
        
        //visit all direction for each cell to find land
        dfs(grid, i - 1, j, m, n);
        dfs(grid, i + 1, j, m, n);
        dfs(grid, i, j - 1, m, n);
        dfs(grid, i, j + 1, m, n);
    }
};