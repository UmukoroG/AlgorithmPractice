class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) return -1;
        int l=0;
        int r=nums.size()-1;
        int minimum=INT_MAX;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r]){
                l=mid+1;
                minimum=min(minimum,nums[mid]);
            }
            else{
                r=mid;
                minimum=min(minimum, nums[mid]);
            }
        }
        return minimum;
    }
};