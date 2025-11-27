class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.empty()) return {{}};

        vector<vector<string>> res;

        unordered_map<string, vector<string>> str;

        for(auto& i : strs){
            string s= i;
            sort(s.begin(), s.end());
            str[s].push_back(i);
            
        }

        for(auto& pair : str){
            res.push_back(pair.second);
        }
        return res;
    }
};