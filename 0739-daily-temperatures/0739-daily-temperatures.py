class Solution:
    def dailyTemperatures(self, temp: List[int]) -> List[int]:
        li = list()
        n = len(temp)
        ans = [0 for x in range(n)]

        for i in range(n-1, -1, -1):
            if len(li)==0:
                ans[i] = 0
            else:
                while len(li)>0 and li[-1][0] <= temp[i]:
                    li.pop()
                if len(li)==0:
                    ans[i] = 0
                else:
                    ans[i] = li[-1][1]-i
            li.append([temp[i], i])
        return ans
        