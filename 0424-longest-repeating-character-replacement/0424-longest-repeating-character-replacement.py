class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        mp={}
        res,l=0,0
        for r in range(len(s)):
            mp[s[r]]=1+mp.get(s[r],0)

            while (r-l+1)-max(mp.values()) > k: # no. of replacemet needed
                mp[s[l]]-=1 #we increase the left window but remove 1 from the map count
                l+=1
            res=max(res,r-l+1)

        return res

