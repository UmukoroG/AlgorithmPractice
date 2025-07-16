class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount % 2 != 0 && all_of(coins.begin(), coins.end(), [](int c){ return c % 2 == 0; }))
            return 0;

        vector<int> dp(amount+1, 0);

        dp[0]=1;
        for(int coin:coins){
            for(int i= coin; i<=amount; i++){
                dp[i]+=dp[i-coin];
            }
        }

        return dp[amount];
    }
    
};