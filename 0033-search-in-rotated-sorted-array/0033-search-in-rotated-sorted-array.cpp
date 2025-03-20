class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l =0; 
        int r=nums.size()-1;

        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[l]<=nums[mid]){//left part sorted
                if(nums[l]<=target && target<nums[mid]){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else {//if(nums[r]>nums[mid]){//right part sorted
                if(nums[mid]<target && target <= nums[r]){
                    l=mid+1;
                }
                else{
                    l=mid-1;
                }

            }
        }
        return -1;
    }
};