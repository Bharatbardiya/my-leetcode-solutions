class Solution {
public:
    vector<vector<int>>help = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    void dfs(vector<vector<bool>>&vis, vector<vector<char>>&board, int i, int j){
        // cout<<i<<","<<j<<"),";
        int n = board.size(), m = board[0].size();
        if(i<0 or j<0 or i>=n or j>=m) return;
        if(vis[i][j]) return;
        vis[i][j]=true;
        if(board[i][j]=='X') return;

        for(auto v : help){
            int ii = v[0]+i, jj = v[1]+j;
            dfs(vis, board, ii,jj);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m, false));

        for(int i = 0; i<n; i++){
            dfs(vis, board, i,0);
            dfs(vis, board, i,m-1);
        }
        for(int j = 1; j<m-1; j++){
            dfs(vis, board, 0, j);
            dfs(vis, board, n-1, j);
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j]==false){
                    board[i][j]='X';
                }
            }
        }
    }
};