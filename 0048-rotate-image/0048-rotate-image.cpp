class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int left = 0, right = n-1, top = 0, bottom = n-1;
        while(left<=right and top<=bottom){
            int l = left, r = right, t = top, b = bottom;
            while(l<right){
                swap(matrix[top][l], matrix[t][right]);
                swap(matrix[top][l], matrix[b][left]);
                swap(matrix[b][left], matrix[bottom][r]);
                l++; t++; b--; r--;
            }
            left++; right--; top++; bottom--;
        }
    }
};