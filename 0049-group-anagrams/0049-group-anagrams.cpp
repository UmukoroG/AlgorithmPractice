class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.empty()) return {{}};

        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;

        for(auto& i:strs){
            string s = i;
            sort(s.begin(), s.end());
            mp[s].push_back(i);
        }

        for(auto& pair: mp){
            res.push_back(pair.second);
        }

        return res;
    }
};