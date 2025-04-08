class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort(reverse=True)
        s.sort(reverse=True)

        ans,i,j,n,m = 0,0,0,len(g), len(s)

        while i<n and j<m:
            if g[i]>s[j]:
                i+=1
            elif s[j]>=g[i]:
                ans+=1
                i+=1
                j+=1
        return ans
