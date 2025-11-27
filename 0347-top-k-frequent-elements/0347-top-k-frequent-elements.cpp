class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> res;

        unordered_map<int, int> mp;
        for(auto& x:nums){
            mp[x]++;
        }
        
        // minHeap: (frequency, number)    
        priority_queue< pair<int,int>, 
                        vector<pair<int,int>>, 
                        greater<pair<int,int>>> minHeap;

        for(auto& pair:mp){
            int num = pair.first;
            int fre = pair.second;

            minHeap.push({fre, num});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }

        while(!minHeap.empty()){
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res;
    }
};