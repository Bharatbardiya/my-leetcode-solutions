class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        
        vector<vector<int>>effort(row, vector<int>(col, INT_MAX));
        vector<vector<bool>>vis(row, vector<bool>(col, false));
        vector<vector<int>>dir = {{-1,0}, {1,0}, {0,1}, {0,-1}};

        effort[0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0,0,0});
        int j = 0;
        while(true){
            auto vpr = pq.top();
            pq.pop();
            int ef = vpr[0], i = vpr[1], j = vpr[2];
            if(i==row-1 and j==col-1) return ef;
            vis[i][j] = true;
            for(auto v : dir){
                int ii = v[0]+i, jj = v[1]+j;
                if(ii<0 or jj<0 or ii>=row or jj>=col) continue;
                if(vis[ii][jj]) continue;
                int newEffort = max(abs(heights[i][j]-heights[ii][jj]), effort[i][j]) ;
                if(effort[ii][jj]>newEffort){
                    pq.push({newEffort, ii, jj});
                    effort[ii][jj] = newEffort;
                }
            }
            j++;
        }
        return effort[row-1][col-1];
    }
};