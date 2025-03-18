class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int row = matrix.size();
        int col = matrix[0].size();
        
        // Start from the top-right corner
        int i = 0, j = col - 1;

        while (i < row && j >= 0) {
            if (matrix[i][j] == target) {
                return true; 
            } else if (matrix[i][j] < target) {
                i++; 
            } else {
                j--; 
            }
        }

        return false; 
    }
};
