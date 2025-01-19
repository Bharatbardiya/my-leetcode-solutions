class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        vector<vector<int>>costs(m, vector<int>(n, 1e9));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        
        costs[0][0] = 0;
        pq.push({0,0,0});

        while(pq.size()>0){
            
            auto vi = pq.top();
            int cost = vi[0], i = vi[1], j = vi[2];
            pq.pop();
            if(i==m-1 and j==n-1) return cost;

            for(int itr = 0; itr<4; itr++){
                int ii = dirs[itr][0]+i, jj = dirs[itr][1]+j;
                if(ii<0 or jj<0 or ii>=m or jj>=n) continue;
                int newCost = cost;
                if(grid[i][j]!=itr+1){
                    newCost++;
                }
                if(costs[ii][jj]>newCost){
                    pq.push({newCost, ii,jj});
                    costs[ii][jj] = newCost;
                }
            }
        }
        return costs[m-1][n-1];
    }
};