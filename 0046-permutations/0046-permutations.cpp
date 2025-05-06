class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        vector<bool> used(nums.size(), false); // {false, false, false}
        dfs(nums, res, perm,used);
        return res;

        
    }
private:
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& perm, vector<bool>& used){
        if(perm.size()==nums.size()){//base case
            res.push_back(perm);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(used[i]==true) continue;

            perm.push_back(nums[i]);
            used[i]=true;
            dfs(nums, res, perm, used);

            perm.pop_back();
            used[i]=false;
        }
    }
};