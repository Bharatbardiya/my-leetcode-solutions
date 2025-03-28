class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows==1:
            return [[1]]
        elif numRows==2:
            return [[1],[1,1]]
        
        grid = [[1], [1,1]]

        for i in range(2, numRows):
            arr = grid[-1]
            brr = [1]
            for i in range(len(arr)-1):
                brr.append(arr[i]+arr[i+1])
            brr.append(1)
            grid.append(brr)

        return grid
            
        