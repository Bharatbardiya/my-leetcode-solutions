class Solution {
public:
    int fun(int a, int b, vector<vector<int>>&dp){
        if(a==0 or b==0){
            return 1;
        }
        if(dp[a][b]!=-1) return dp[a][b];
        return dp[a][b] = fun(a-1, b, dp) + fun(a, b-1, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return fun(m-1, n-1, dp);
    }
};