class Solution {
public:
    long long fun(vector<vector<int>>&mywords, int i, string &target, int j, vector<vector<int>>&dp){
        if(j<0) return 1;
        if(i<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        int count = mywords[i][target[j]-'a'];
        long long ans = (count)*fun(mywords, i-1, target, j-1, dp);
        ans += fun(mywords, i-1, target, j, dp);
        int mod = 1e9+7;
        return dp[i][j] = (ans)%(mod);
    }
    int numWays(vector<string>& words, string target) {
        int n = words[0].length(), m = target.length();
        vector<vector<int>>mywords(n, vector<int>(26));
        for(auto &s : words){
            for(int i = 0; i<n; i++){
                mywords[i][s[i]-'a']++;
            }
        }

        // vector<vector<long long>>dp(n+1, vector<long long>(m+1, 0));
        vector<long long>prev(m+1, 0), curr(m+1,0);
        prev[0] = 1;
        curr[0] = 1;
        int mod = 1e9+7;

        // for(int i = 0; i<=n; i++) dp[i][0]=1;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m;  j++){
                int count = mywords[i-1][target[j-1]-'a'];
                curr[j] = (count*prev[j-1] + prev[j])%mod;
            }
            prev = curr;
        }
        return prev[m];
    }
};