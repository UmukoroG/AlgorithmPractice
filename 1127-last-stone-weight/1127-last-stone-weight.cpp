class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        while(stones.size()>1){
            sort(stones.begin(), stones.end()); //not optimal
            int curr = stones.back() - stones[stones.size()-2];
            stones.pop_back();
            stones.pop_back();
            if(curr!=0){
                stones.push_back(curr);
            }
        }
        return stones.empty() ? 0 : stones[0];
    }
};