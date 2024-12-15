class Solution {
public:
    int fun(vector<vector<int>>&triangle, int i, int j, vector<vector<int>>&dp){
        if(i==triangle.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = triangle[i][j]+min(fun(triangle, i+1, j, dp), fun(triangle, i+1, j+1, dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return fun(triangle, 0, 0, dp);
    }
};