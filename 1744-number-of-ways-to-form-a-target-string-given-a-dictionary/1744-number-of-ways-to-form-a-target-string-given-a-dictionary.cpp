class Solution {
public:
    long long fun(vector<vector<int>>&mywords, int i, int n, string &target, int j, vector<vector<int>>&dp){
        if(j==target.length()) return 1;
        if(i==n) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        int count = mywords[i][target[j]-'a'];
        long long ans = (count)*fun(mywords, i+1, n, target, j+1, dp);
        ans += fun(mywords, i+1, n, target, j, dp);
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

        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));

        return fun(mywords, 0, n, target, 0, dp);
    }
};