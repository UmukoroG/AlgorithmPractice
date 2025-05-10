class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        dfs(nums, res, subset, 0);
        sort(res.begin(), res.end());
        return res;
    }
private:
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& subset, int start){
        res.push_back(subset);
          
        for(int i=start; i<nums.size(); i++){
            //skips duplicates
            if(i>start && nums[i]==nums[i-1]){
                continue;
            }
            subset.push_back(nums[i]); 
            dfs(nums, res, subset, i+1);

            subset.pop_back(); 

        }
    }
};