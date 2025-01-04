class Solution {
public:
    void dfs(vector<vector<int>>&grid, int i, int j, vector<pair<int,int>>&points, vector<vector<bool>>&vis){
        int n = grid.size(), m = grid[0].size();
        if(i>=n or j>=m or i<0 or j<0) return;
        if(vis[i][j]) return;
        if(grid[i][j]==0) return;

        vis[i][j]=true;
        points.push_back({i,j});
        dfs(grid, i-1, j, points, vis);
        dfs(grid, i+1, j, points, vis);
        dfs(grid, i, j-1, points, vis);
        dfs(grid, i, j+1, points, vis);
    }
    void transform(vector<pair<int,int>>&points, int a, int b){
        for(auto &pr: points){
            pr.first-=a; pr.second-=b;
        }
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m,false));
        set<vector<pair<int,int>>>st;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j]==false and grid[i][j]==1){
                    vector<pair<int,int>>points;
                    dfs(grid, i,j, points, vis);
                    transform(points, i,j);
                    // sort(points.begin(), points.end());
                    st.insert(points);
                }
            }
        }
        return st.size();
    }
};