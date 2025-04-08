class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        ind = -1
        st = set()
        for i in range(len(nums)-1, -1, -1):
            if nums[i] in st:
                ind = i
                break
            st.add(nums[i])
        # print(ind)
        return (ind+1)//3 if (ind+1)%3==0 else (ind+1)//3+1

        