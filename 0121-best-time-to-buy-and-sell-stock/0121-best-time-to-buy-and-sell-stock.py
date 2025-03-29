class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxi, ans = prices[-1], 0

        for i in range(len(prices)-1, -1, -1):
            maxi = max(maxi, prices[i])
            # print(maxi, prices[i])
            ans = max(ans, maxi-prices[i])
        
        return ans