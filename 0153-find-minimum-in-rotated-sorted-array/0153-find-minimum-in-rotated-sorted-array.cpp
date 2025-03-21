class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) return -1;
        // int l=0;
        // int r=nums.size()-1;
        // int min=INT_MAX;
        // while(l<=r){
        //     if(nums[l]>nums[r] && nums[r]>min){
        //         min=nums[r];
        //         r--;
        //     }
        //     else {//if(nums[l]<=nums[r] && nums[l]>min){
        //         min=nums[l];
        //         l++;
        //     }
        // }
        // return min;

        sort(nums.begin(), nums.end());
        return nums[0];
    }
};