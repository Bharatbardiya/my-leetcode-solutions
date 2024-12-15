class Solution {
public:

    bool fun(vector<vector<int>>&grid, int i, int j, int t1, int t2, vector<vector<vector<int>>>&dp){
        int m = grid.size(), n = grid[0].size();
        if(i==m-1 and j==n-1){
            if(grid[i][j]==0) t1--;
            else t2--;
            return t1==t2;
        }
        if(i==m or j==n) return false;

        if(grid[i][j]==0) t1--;
        else t2--;

        if(t1<0 or t2<0) return false;
        
        if(dp[i][j][t1] != -1) return dp[i][j][t1];
        return dp[i][j][t1] = (fun(grid,i+1,j, t1, t2,dp) || fun(grid,i,j+1,t1,t2,dp));
    }
    bool isThereAPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(m+n%2==0) return false;

        int t = (m+n-1)/2;
        vector<vector<vector<int>>>dp(m+1, vector<vector<int>>(n+1, vector<int>(t+1, -1)));

        return fun(grid, 0, 0, t, t, dp);
    }
};