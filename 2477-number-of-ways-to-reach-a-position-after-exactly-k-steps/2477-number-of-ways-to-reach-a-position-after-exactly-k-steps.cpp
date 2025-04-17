class Solution {
public:
    int mod = 1e9+7;
    long long ways(int start, int end, int k, vector<vector<long long>>&dp){
        int dif = abs(start-end);
        if(dif==k) return 1;
        else if(dif>k) return 0;
        if(dp[dif][k]!=-1) return dp[dif][k];
        dp[dif][k] = ways(start+1, end, k-1, dp) + ways(start-1, end, k-1, dp);
        dp[dif][k] %= mod;
        return dp[dif][k];
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<long long>>dp(2002, vector<long long>(1001, -1));
        return ways(startPos, endPos, k, dp);
    }
};