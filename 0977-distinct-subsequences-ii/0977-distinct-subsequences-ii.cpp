class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.length(), mod = 1e9+7;
        unordered_map<char,int>mp;
        vector<long long>dp(n+1, 0);
        dp[0] = 1;

        for(int i = 0; i<n; i++){
            dp[i+1] = 2*dp[i];
            if(mp.find(s[i])!=mp.end()){
                dp[i+1] -= dp[mp[s[i]]];
            }
            dp[i+1] %= mod;
            mp[s[i]]  = i;
        }
        // for(auto x : dp) cout<<x<<", ";
        dp[n]--;
        dp[n] = dp[n]%mod;;
        if(dp[n]<0) dp[n]+=mod;
        return dp[n];
    }
};