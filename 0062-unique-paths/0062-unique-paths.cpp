class Solution {
public:
    int fun(int i, int j, vector<vector<int>>&dp){
			if(i==0 or j==0) return 1;
			// if(i==-1) return 0;
			// if(j==-1) return 0;
            if(dp[i][j]!=-1) return dp[i][j];
			return dp[i][j] = fun(i-1,j, dp) + fun(i,j-1, dp);
		}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,1));

        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};