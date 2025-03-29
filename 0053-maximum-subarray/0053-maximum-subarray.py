class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        curr, maxi = 0, -1e9
        
        for num in nums:
            curr += num
            maxi = max(curr,maxi)
            if curr<0:
                curr = 0
            
        return maxi

        