class Solution {
public:
    int mod = 1e9+7;
    int reqfun(int val, int low, int high, int zero, int one, vector<int>&dp){
        if(val>high) return 0;
        if(dp[val]!=-1) return dp[val];

        long long ans = 0;
        if(val>=low and val<=high) ans = 1;
        ans += reqfun(val+zero, low, high, zero, one, dp);
        ans += reqfun(val+one, low, high, zero, one, dp);
        return dp[val] = (ans)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1, -1);
        return reqfun(0, low, high, zero, one, dp);
    }
};