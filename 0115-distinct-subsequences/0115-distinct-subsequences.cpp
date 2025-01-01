class Solution {
public:
    int fun(string &s, string &t, int i, int j, vector<vector<int>>&dp){
        if(j<0) return 1;
        if(i<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        int val1 = fun(s, t, i-1, j, dp), val2 = 0;
        if(s[i]==t[j]){
            val2 = fun(s, t, i-1, j-1, dp);
        }
        return dp[i][j] = val1+val2;
    }
    int numDistinct(string s, string t) {
        int n1 = s.length(), n2 = t.length();
        vector<vector<int>>dp(n1+1, vector<int>(n2+1, -1));
        return fun(s,t,n1-1, n2-1, dp);
    }
};