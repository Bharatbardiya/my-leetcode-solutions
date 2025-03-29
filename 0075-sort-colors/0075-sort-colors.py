class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i, j, k = -1, 0, len(nums)-1

        while j<=k:
            if i==j:
                j+=1
            elif nums[j]==2:
                nums[k], nums[j] = nums[j], nums[k]
                k-=1
            elif nums[j]==0:
                i+=1
                nums[i], nums[j] = nums[j], nums[i]
            else:
                j+=1
        
