class Solution {
public:
    int cherryPickReq(vector<vector<int>>& grid, int i1, int j1, int i2, int j2,  vector<vector<vector<vector<int>>>>& dp){
        int n = grid.size();
        if(i1==n-1 and i2==n-1 and j1==n-1 and j2==n-1) return grid[i1][j1];

        if(i1<0 or j1<0 or i1>=n or j1>=n or i2<0 or j2<0 or i2>=n or j2>=n){
            return INT_MIN;
        }
        if(grid[i1][j1]==-1 or grid[i2][j2]==-1) return INT_MIN;

        if(dp[i1][j1][i2][j2]!=-1) return dp[i1][j1][i2][j2];
        int curr = grid[i1][j1]+grid[i2][j2];
        if(i1==i2 and j1==j2) curr-=grid[i2][j2];

        return dp[i1][j1][i2][j2] = curr + max(
            max(cherryPickReq(grid, i1+1, j1, i2+1, j2, dp), 
                cherryPickReq(grid, i1+1, j1, i2, j2+1, dp)), 
            max(cherryPickReq(grid, i1, j1+1, i2+1, j2, dp), 
                cherryPickReq(grid, i1, j1+1, i2, j2+1, dp)));

    }


    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<vector<int>>>>dp(n, 
            vector<vector<vector<int>>>(n, 
            vector<vector<int>>(n,
            vector<int>(n,-1))));
        int val = cherryPickReq(grid, 0,0,0,0, dp);
        if(val<0) return 0;
        return val;
    }   

        /*
        [[1,1,1,1,0,0,0]
        ,[0,0,0,1,0,0,0]
        ,[0,0,0,1,0,0,1]
        ,[1,0,0,1,0,0,0]
        ,[0,0,0,1,0,0,0]
        ,[0,0,0,1,0,0,0]
        ,[0,0,0,1,1,1,1]]
        */
};