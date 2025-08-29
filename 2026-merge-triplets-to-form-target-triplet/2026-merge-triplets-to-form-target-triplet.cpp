class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> valid;

        for(const auto& t: triplets){
            if(t[0]>target[0] || t[1]>target[1] || t[2]>target[2]){
                continue;
            }
            for(int i=0; i<t.size(); i++){
                if(t[i]==target[i]){
                    valid.insert(i);
                }
            }
        }
        return valid.size()==3;
    }
};