class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][0]!=0) return -1;
        int level = 1;
        vector<vector<int>>dir = {{-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}};
        
        vector<vector<int>>vis(n, vector<int>(m,false));
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0] = true;

        while(q.size()>0){
            
            int x = q.size();
            for(int k = 0; k<x; k++){
                auto pr = q.front(); q.pop();
                int i = pr.first, j = pr.second;
                if(i==n-1 and j==m-1) return level;
                for(auto v : dir){
                    int ii = v[0]+i, jj = v[1]+j;
                    if(ii<0 or ii>=n or jj<0 or jj>=m) continue;
                    if(vis[ii][jj]) continue;
                    if(grid[ii][jj]!=0) continue;
                    // if(ii==n-1 and jj==m-1) return level+1;
                    q.push({ii,jj});
                    vis[ii][jj] = true;
                }
            }
            level++;
        }
        return -1;
    }
};