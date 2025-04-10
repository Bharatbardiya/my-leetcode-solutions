class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

        for(int i = 0; i<n; i++){
            if(obstacleGrid[0][i]==1) break;
            dp[0][i] = 1;
        }
        for(int i = 0; i<m; i++){
            if(obstacleGrid[i][0]==1) break;
            dp[i][0] = 1;
        }

        for(int i = 1; i<n; i++){
            for(int j = 1; j<m; j++){
                if(obstacleGrid[j][i]==0){
                    dp[j][i] = dp[j-1][i]+dp[j][i-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};