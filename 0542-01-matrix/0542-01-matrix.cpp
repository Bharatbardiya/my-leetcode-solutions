class Solution {
public:
    vector<vector<int>>help = {{-1,0},{1,0}, {0,-1}, {0,1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>>dis(n, vector<int>(m,0));
        vector<vector<bool>>vis(n, vector<bool>(m,false));
        queue<vector<int>>q;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j]==0){
                    vis[i][j]=true;
                    q.push({i,j,0});
                }
                
            }
        }
        while(q.empty()==false){
            
            auto v = q.front();
            q.pop();
            int x = v[0], y = v[1], level = v[2];
            // cout<<x<<","<<y<<"),";
            dis[x][y] = level;

            for(auto vv : help){
                int ii = x+vv[0], jj = y+vv[1];
                if(ii>=n or jj>=m or ii<0 or jj<0) continue;
                else if(mat[ii][jj]==1 and vis[ii][jj]==false){
                    q.push({ii,jj,1+level});
                    vis[ii][jj] = true;
                }
            }
        }

        return dis;
    }
};