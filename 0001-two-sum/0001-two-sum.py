class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp= dict()
        # for i in nums:
        for index, value in enumerate(nums):
            if (target-value) in mp:
                return [index,mp[target-value]]
            else:
                mp[value]=index
            
        return []
        