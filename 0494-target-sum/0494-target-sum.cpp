class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return backtrack(0,0, nums, target);
    }

private:
    int backtrack(int i, int cur_sum, vector<int>& nums, int target){
        if(i==nums.size()){
            return 1 ? cur_sum == target : 0;
        }

        return (
            backtrack(i+1, cur_sum+nums[i], nums, target)+
            backtrack(i+1, cur_sum-nums[i], nums, target)
        );
    }
};