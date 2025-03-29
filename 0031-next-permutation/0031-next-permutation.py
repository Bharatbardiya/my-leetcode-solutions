class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        ind, mini = -1, 1000
        for i in range(len(nums)-1, 0, -1):
            if nums[i]>nums[i-1]:
                ind = i-1
                break
        if ind==-1:
            nums.sort()
        
        ind2 = -1
        for i in range(ind+1, len(nums)):
            if nums[i]>nums[ind]:
                ind2 = i
        # print(ind,ind2)
        # print(nums)
        nums[ind], nums[ind2] = nums[ind2], nums[ind]
        # print(nums)
        nums[ind+1:] = sorted(nums[ind+1:])
        # print(nums)
