class Solution:
    def maxArea(self, height: List[int]) -> int:
        l,r = 0,len(height)-1
        res=0
        while r>l:
            a=(r-l) * min(height[l],height[r]) #area of a rec. l*w
            res=max(res, a)
            if height[r]>height[l]:
                l+=1
            else:
                r-=1 # we can increase l or right for when l and r are equal right or r<l
        return res        