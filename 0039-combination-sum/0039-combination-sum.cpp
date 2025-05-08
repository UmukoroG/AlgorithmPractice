class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combn;
        dfs(candidates,res, combn, target, 0);
        return res;
    }
private:
    void dfs(vector<int>& candidates, vector<vector<int>>& res, vector<int>& combn, int target, int i){
        if(i>= candidates.size()) return; //i could exceeds the bounds
        
        int sum = accumulate(combn.begin(), combn.end(),0);
        if(sum==target){//check if combn sum == target
            res.push_back(combn);
            return;
        }
        else if(sum>target){
            return;
        }

        combn.push_back(candidates[i]); //include i, repeating/reusing combn
        dfs(candidates, res, combn, target, i);

        combn.pop_back();//don't include i
        dfs(candidates, res, combn, target, i+1);
    }
};