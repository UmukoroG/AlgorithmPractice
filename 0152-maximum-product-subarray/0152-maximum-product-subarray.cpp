class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=*max_element(nums.begin(), nums.end());
        int currMin=1;
        int currMax=1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                currMin=1;
                currMax=1;
                continue;
            }

            int temp=currMax*nums[i];
            currMax=max({nums[i]*currMax, nums[i]*currMin,nums[i]});
            currMin=min({temp, nums[i]*currMin, nums[i]});
            res=max(res,currMax);
        }
        return res;
    }
};