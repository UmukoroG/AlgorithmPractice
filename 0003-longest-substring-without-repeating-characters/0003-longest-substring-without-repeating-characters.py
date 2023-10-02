class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        cSet=set()
        l=0
        res=0

        #using the sliding window techniques with a left and right pointer
        for r in range(len(s)):
            while s[r] in cSet:
                cSet.remove(s[l])
                l+=1
            cSet.add(s[r])
            res=max(res, r-l+1)
        return res