class Solution {
public:
    int fun(string &s1, int i, int j, vector<vector<int>>&dp){
        if(i>=j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s1[j]) return dp[i][j] = fun(s1, i+1, j-1, dp);
        return dp[i][j] = 1+min(fun(s1, i+1, j, dp), fun(s1, i, j-1, dp));
    }

    int minInsertions(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int n = s.length();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        return fun(s, 0, n-1, dp);
    }
};