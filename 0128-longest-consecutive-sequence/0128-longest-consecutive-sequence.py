class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        Set = set(nums) #no duplicates
        count =0 #count the start of each new sequence
        longest=0
        
        #Using a number line system
        for i in nums:
            if i-1 not in Set:#no left neighbour -> start of a sequence
                count=0 #restarts counting for new sequence
                while(i+count) in Set:
                    count+=1
                longest=max(count,longest)
            if i-1 in Set:    
                continue #not the first sequence
        return longest