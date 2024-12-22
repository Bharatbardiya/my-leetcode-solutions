class Solution {
public:
    int lcs(string &s1, string &s2, int i, int j, vector<vector<int>>&dp){
        if(i<0 or j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j] = 1+lcs(s1,s2, i-1, j-1, dp);
        return dp[i][j] = max(lcs(s1,s2,i-1,j, dp), lcs(s1, s2, i, j-1, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1));

        // return lcs(text1, text2, n-1, m-1, dp);

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};