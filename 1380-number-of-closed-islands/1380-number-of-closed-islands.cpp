class Solution {
public:
    vector<vector<int>>dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    void dfs(vector<vector<int>>&grid, vector<vector<bool>>&vis, int i, int j){
        int n = grid.size(), m = grid[0].size();
        if(i>=n or j>=m or i<0 or j<0) return;
        if(grid[i][j]==1) return;
        if(vis[i][j]==true) return;

        vis[i][j] = true;

        for(auto dir : dirs){
            int ii = dir[0]+i, jj = dir[1]+j;
            dfs(grid, vis, ii, jj);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m, false));

        for(int i = 0; i<n; i++){
            if(grid[i][0]==0) dfs(grid, vis, i, 0);
            if(grid[i][m-1]==0) dfs(grid, vis, i, m-1);
        }
        for(int j = 0; j<m; j++){
            if(grid[0][j]==0) dfs(grid, vis, 0, j);
            if(grid[n-1][j]==0) dfs(grid, vis, n-1, j);
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j]==false and grid[i][j]==0){
                    dfs(grid, vis, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};