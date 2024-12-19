class Solution {
public:
    int fun(string &s1, string &s2, int i, int j, vector<vector<int>>&dp){
        if(i==s1.length()){
            if(j==s2.length()) return 0;
            return INT_MAX;
        }
        if(j==s2.length()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) j++;
        int val = fun(s1, s2, i+1, j,dp);
        if(val==INT_MAX) return dp[i][j] = val;
        return dp[i][j] = 1+val;
    }

    string minWindow(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        
        int ind = -1, len = INT_MAX;
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));

        for(int i = 0; i<n; i++){
            int t = fun(s1, s2, i, 0, dp);
            if(t<len){
                ind = i;
                len = t;
            }
        }
        
        if(len==INT_MAX) return "";
        return s1.substr(ind, len);
    }
};