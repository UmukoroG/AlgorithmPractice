class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA=INT_MIN;

        int l=0;
        int r=height.size()-1;

        while(l<r){
            int area = (r-l) * min(height[r], height[l]);
            maxA = max(area, maxA); 
            if(height[r]>=height[l]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxA;
    }
};