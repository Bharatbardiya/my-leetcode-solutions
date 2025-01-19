class Solution {
    vector<vector<int>>dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        vector<vector<bool>>vis(m, vector<bool>(n, false));

        int currHigh = 0;
        for(int i = 0; i<m; i++){
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n-1], i, n-1});
            vis[i][0] = true;
            vis[i][n-1] = true;
        }
        for(int j = 1; j<n-1; j++){
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m-1][j], m-1, j});
            vis[0][j] = true;
            vis[m-1][j] = true;
        }
        int ans = 0;

        while(pq.size()>0){
            auto vi = pq.top(); pq.pop();
            int curr = vi[0], i = vi[1], j = vi[2];
            currHigh = curr;

            for(auto dir : dirs){
                int ii = dir[0]+i, jj = dir[1]+j;
                if(ii<0 or ii>=m or jj<0 or jj>=n) continue;
                if(vis[ii][jj]) continue;
                if(heightMap[ii][jj]<currHigh){
                    ans += (currHigh-heightMap[ii][jj]);
                }
                pq.push({max(currHigh, heightMap[ii][jj]), ii, jj});
                vis[ii][jj] = true;
            }
        }
        return ans;

    }
};