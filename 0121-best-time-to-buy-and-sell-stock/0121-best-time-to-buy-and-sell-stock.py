class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        l=0 #buy
        r=1 #sell
        maxP=0
        while r<len(prices): #check array bounds
            if prices[l]<prices[r]: #profitable transaction
                tempMaxP=prices[r]-prices[l]
                maxP=max(maxP, tempMaxP)
            else:   #not profitable
                l=r
            r+=1    #we increase regardless to find highest sell day
        return maxP
        