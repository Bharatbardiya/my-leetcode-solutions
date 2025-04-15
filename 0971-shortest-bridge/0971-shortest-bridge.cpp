class Solution {
public:
    vector<vector<int>>dirs = {{-1,0},{1,0}, {0,-1}, {0,1}};
    void dfs(vector<vector<int>>&grid, vector<vector<bool>>&vis, int i, int j){
        
        int n = grid.size(), m = grid[0].size();
        if(i<0 or j<0 or i>=n or j>=m) return;
        if(grid[i][j]==0 or vis[i][j]==true) return;
        vis[i][j] = true;

        for(auto dir : dirs){
            int ii = i+dir[0], jj = j+dir[1];
            dfs(grid, vis, ii, jj);
        }

    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>>vis(n, vector<bool>(m, false));
        for(int i = 0; i<n; i++){
            bool call = false;
            for(int j = 0; j<m; j++){
                if(grid[i][j]==1){
                    dfs(grid, vis, i,j);
                    call=true;
                    break;
                }
            }
            if(call) break;
        }

        queue<pair<int,int>>q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j]) q.push({i,j});
            }
        }
        int ans = 0;
        while(q.size()>0){
            int size = q.size();
            for(int itr = 0; itr<size; itr++){
                auto pr = q.front(); q.pop();
                int i = pr.first, j = pr.second;
                // cout<<i<<","<<j<<"),";
                if(ans>0 and grid[i][j]==1) return ans-1;
                for(auto dir : dirs){
                    int ii = dir[0]+i, jj = dir[1]+j;
                    if(ii>=n or jj>=m or ii<0 or jj<0) continue;
                    if(vis[ii][jj]==true) continue;
                    vis[ii][jj] = true;
                    q.push({ii,jj});
                }
            }
            ans++;
        }
        return -1;
    }
};