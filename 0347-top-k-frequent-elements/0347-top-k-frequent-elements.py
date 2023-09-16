class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mp={}

        for i in range(len(nums)):
            mp[nums[i]]=1+mp.get(nums[i],0)

        res=[]
        highestK=sorted(mp.values(), reverse=True)[k-1]
        #get the values, reverse and sort in desc order then return value at [k-1] index since counter starts at 0

        for i in mp:
            if mp[i]>=highestK: #add element greater than or equal to highestK 
                res.append(i)
            else:
                continue

        return res
        