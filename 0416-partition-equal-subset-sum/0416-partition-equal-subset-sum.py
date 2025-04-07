class Solution:
    
    def canPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        dp = [[-1]*40002 for i in range(n+1)]
        def fun(nums, i, curr):
            if i==-1:
                if curr==0:
                    return True
                return False
            if dp[i][curr+20000]!=-1:
                return dp[i][curr+20000]
            dp[i][curr+20000] = fun(nums, i-1, curr+nums[i]) or fun(nums, i-1, curr-nums[i])
            return dp[i][curr+20000]
        return fun(nums, n-1, 0)
        