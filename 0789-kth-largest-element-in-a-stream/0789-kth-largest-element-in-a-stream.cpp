class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int position;
    KthLargest(int k, vector<int>& nums) {
        for(int i=0; i<nums.size();i++){
            minHeap.push(nums[i]);
        }
        position = k;
        
    }
    
    int add(int val) {
        minHeap.push(val);
        while(position!=minHeap.size()){
            minHeap.pop();
        }
        int largest = minHeap.top();
        return largest;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */