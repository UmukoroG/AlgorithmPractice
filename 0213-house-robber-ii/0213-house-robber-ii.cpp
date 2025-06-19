class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==0) return 0;
        if(n==1) return nums[0];

        return max(robLinear(nums,0,n-2),robLinear(nums,1,n-1));
        // split into 2 ranges - exclude last house or exclude first house
    }

    int robLinear(vector<int>& nums, int start, int end){
        int n=end-start+1;

        vector<int> dp(n);

        if(n==0) return 0;
        if(n==1) return nums[start];

        dp[0]=nums[start];
        dp[1]=max(nums[start], nums[start+1]);

        for(int i=2; i<n; i++){
            dp[i]=max(nums[start+i]+dp[i-2], dp[i-1]);
        }
        

        return dp[n-1];
    }
};