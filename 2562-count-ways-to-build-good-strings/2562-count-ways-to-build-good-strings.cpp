class Solution {
public:
    int mod = 1e9+7;
    int fun(int val, int x1, int x2, vector<long long>&dp){
        if(val<0) return 0;
        else if(val==0) return 1;
        if(dp[val]!=-1) return dp[val];

        return dp[val] = (fun(val-x1, x1, x2, dp)+fun(val-x2, x1,x2, dp))%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long>dp(high+1, -1);
        int ans = 0;
        for(int i = low; i<=high; i++){
            ans += fun(i, zero, one, dp);
            // ans += dp[i];
            ans = (ans%mod);
        }
        return ans;
    }
};