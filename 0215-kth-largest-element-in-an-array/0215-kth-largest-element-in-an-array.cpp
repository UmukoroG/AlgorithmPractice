class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        int kVal = -1;
        for(int num: nums){
            maxHeap.push(num);
        }

        int count = 0;
        while(count < k){
            kVal = maxHeap.top();
            maxHeap.pop();
            count++;
        }
        return kVal;


    }
};