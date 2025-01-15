class Solution {
public:
    vector<vector<int>>help = {{0,1}, {0,-1}, {-1,0}, {1,0}};
    bool isReachable(vector<vector<int>>&grid, int level){
        int n = grid.size();
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(n, vector<bool>(n,false));
        if(grid[0][0]<=level){
            q.push({0,0}); vis[0][0] = true;
        }
        while(q.size()>0){
            auto pr = q.front();
            q.pop();
            int i = pr.first, j = pr.second;
            if(i==n-1 and j==n-1) return true;
            for(auto v : help){
                int ii = i+v[0], jj = j+v[1];
                if(ii>=n or ii<0 or jj>=n or jj<0) continue;
                if(vis[ii][jj]==false and grid[ii][jj]<=level){
                    q.push({ii,jj});
                    vis[ii][jj] = true;
                }
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int high = 0, low = 0;
        for(auto v : grid){
            for(auto x : v) high = max(high, x);
        }
        int ans = high;
        while(low<=high){
            int mid = (low+high)/2;
            if(isReachable(grid, mid)){
                ans = mid; high = mid-1;
            }
            else{
                low = mid+1;
            }
            // cout<<low<<","<<high<<"),";
        }
        return ans;
    }
};