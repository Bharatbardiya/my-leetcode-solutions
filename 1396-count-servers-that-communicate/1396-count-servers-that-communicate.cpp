class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<int>row(m), col(n);
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==1){
                    row[i]++; col[j]++;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==1 and (row[i]>1 or col[j]>1)) ans++;
            }
        }
        return ans;
    }
};