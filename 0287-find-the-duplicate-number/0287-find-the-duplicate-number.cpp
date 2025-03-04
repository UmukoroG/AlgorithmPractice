class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> Set;

        for(int i=0; i<nums.size(); i++){
            if(Set.find(nums[i])!=Set.end()){
                return nums[i];
            }
            Set.insert(nums[i]);
        }
        return -1;
    }
};