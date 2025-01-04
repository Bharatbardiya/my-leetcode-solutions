class Solution {
public:
    void dfs(vector<vector<int>>&grid, int i, int j, string &path, vector<vector<bool>>&vis, char dir){
        int n = grid.size(), m = grid[0].size();
        if(i>=n or j>=m or i<0 or j<0) return;
        if(vis[i][j]) return;
        if(grid[i][j]==0) return;

        vis[i][j]=true;
        path.push_back(dir);
        dfs(grid, i, j+1, path, vis, 'R');
        dfs(grid, i+1, j, path, vis, 'D');
        dfs(grid, i, j-1, path, vis, 'L');
        dfs(grid, i-1, j, path, vis, 'U');
        path.push_back('0');
    }
    void transform(vector<pair<int,int>>&points, int a, int b){
        for(auto &pr: points){
            pr.first-=a; pr.second-=b;
        }
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m,false));
        unordered_set<string>st;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j]==false and grid[i][j]==1){
                    string path = "";
                    dfs(grid, i,j, path, vis, 'R');
                    st.insert(path);
                }
            }
        }
        return st.size();
    }
};