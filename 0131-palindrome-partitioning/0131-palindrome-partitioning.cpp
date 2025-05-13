class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;
        dfs(res, part,s, 0);
        return res;

        
    }
private:
    void dfs(vector<vector<string>>& res, vector<string>& part, string s, int index){
        if(index>=s.size()){
            res.push_back(part);
            return;
        }

        for(int j=index; j<s.size(); j++){
            if(isPali(s,index, j)){
                part.push_back(s.substr(index,j-index+1));
                dfs(res,part,s,j+1);
                part.pop_back();
            }
        }
    }
    bool isPali(string& s, int start, int end){
        
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
            
        }
        return true;

    }
};