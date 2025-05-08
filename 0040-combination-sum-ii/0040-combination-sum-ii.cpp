class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combn;
        sort(candidates.begin(), candidates.end());
        dfs(candidates,res, combn, target, 0, false);
        return res;
    }
private:
    void dfs(vector<int>& candidates, vector<vector<int>>& res, vector<int>& combn, int target, int i, bool takenPrev){
        if(target == 0){
            res.push_back(combn);
            return;
        }
        if(i >= candidates.size() || target < 0) return;

        // Include current candidate only if it's not a duplicate OR we took the previous one
        if (i == 0 || candidates[i] != candidates[i - 1] || takenPrev) {
            combn.push_back(candidates[i]);
            dfs(candidates, res, combn, target-candidates[i], i + 1, true);  // include path
            combn.pop_back();
        }

        dfs(candidates, res, combn, target, i+1, false); //exclude path
    }
};