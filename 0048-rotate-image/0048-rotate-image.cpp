class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l=0;
        int r=matrix.size()-1;

        while(l<r){
            for(int i=0; i<r-l; i++){
                int top =l;
                int bottom=r;

                //save the topleft value
                int topLeft = matrix[top][l+i];

                //move the bottom left to the topleft
                matrix[top][l+i]=matrix[bottom-i][l];

                //move the bottom right into the bottom left
                matrix[bottom-i][l]=matrix[bottom][r-i];

                //move top right into bottom right
                matrix[bottom][r-i]=matrix[top+i][r];

                //move top left into top right
                matrix[top+i][r] = topLeft;
            }
            r--;
            l++;
        }
    }
};