class Solution:
    
    def helper(self, nums, i, li, ans):
        if i==len(nums):
            return
        li.append(nums[i])
        self.helper(nums, i+1, li, ans)
        ans.append(li[:])
        li.pop()

        while i<len(nums)-1 and nums[i]==nums[i+1]:
            i+=1
        self.helper(nums, i+1, li, ans)

    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        li = list()
        ans = list()
        ans.append([])
        nums.sort()
        self.helper(nums, 0, li, ans)
        # print(ans)
        return ans
        
        