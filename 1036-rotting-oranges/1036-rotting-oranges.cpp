class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int fresh = 0;
        int time=0;
        deque<pair<int,int>> q;

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c]==1){
                    fresh++;
                }
                if(grid[r][c]==2){
                    q.push_back({r,c});
                }
            }
        }

        vector<pair<int, int>> directions ={{0,1}, {0,-1}, {1,0}, {-1,0}};

        while(!q.empty() && fresh>0){
            int size = q.size();
            for(int i=0; i<size; i++){
                int r= q.front().first;
                int c= q.front().second;
                q.pop_front();

                for(auto& [dr,dc] : directions ){
                    int row = dr+r;
                    int col = dc+c;

                    if(row<0 || row==grid.size() || col<0 || col==grid[0].size() || grid[row][col]!=  1){
                        continue;
                    }
                    grid[row][col]=2;
                    q.push_back({row,col});
                    fresh--;
                }
            }
            time++;//a level is completed
        }

        return fresh == 0 ? time : -1;
    }
};
