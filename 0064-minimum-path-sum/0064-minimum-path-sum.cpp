class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int top = 1e9, left = 1e9;
                if(i>0) top = grid[i-1][j];
                if(j>0) left = grid[i][j-1];
                if(i!=0 or j!=0) grid[i][j] += min(top, left);
            }
        }
        return grid[n-1][m-1];
    }
};