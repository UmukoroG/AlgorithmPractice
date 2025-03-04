class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int l=0;
        int r=1;

        while(l<r && r<=nums.size()){
            if(nums[l]==nums[r]){
                return nums[l];
            }
            l++;
            r++;
        }
        return -1;
    }
};