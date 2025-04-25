class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq; // max heap

        for(int i=0; i<stones.size(); i++){
            pq.push(stones[i]);
        }

        while(pq.size()>1){
            int first = pq.top(); //y
            pq.pop();
            int second = pq.top();//x
            pq.pop();
            if(first > second){
                pq.push(first-second);
            }  
        }
        return pq.empty() ? 0 : pq.top();
    }
};