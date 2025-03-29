class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        [[9,4,7]
        ,[8,5,2]
        ,[3,6,1]]

        """
        left, top, right, bottom = 0, 0, len(matrix)-1, len(matrix)-1

        while left<=right and top<=bottom:
            l, r, t, b = left, right, top, bottom
            while l<right:
                # print(i)
                temp = matrix[top][l]
                matrix[top][l] = matrix[b][left]
                matrix[b][left] = matrix[bottom][r]
                matrix[bottom][r] = matrix[t][right]
                matrix[t][right] = temp
                l+=1
                r-=1
                t+=1
                b-=1

            left+=1
            right-=1
            top+=1
            bottom-=1

        