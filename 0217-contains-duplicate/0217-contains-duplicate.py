class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        DuplSet=set() #set object has no duplicate element
        for i in nums:
            if i in DuplSet:
                return True
            else:
                DuplSet.add(i)
        return False
        