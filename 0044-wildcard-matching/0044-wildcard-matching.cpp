class Solution {
public:
    bool fun(string &s, string &p, int i, int j, vector<vector<int>>&dp){
        
        if(i<0 and j<0) return true;
        if(i<0){
            if(p[j]=='*') return fun(s, p, i, j-1, dp);
            else return false;
        }
        if(i<0 or j<0) return false;

        if(dp[i][j]!=-1) return dp[i][j];

        if(p[j]=='?') return dp[i][j] = fun(s, p, i-1, j-1, dp);
        else if(p[j]=='*'){
            return dp[i][j] = (fun(s, p, i-1, j, dp) or fun(s, p, i, j-1, dp));
        }
        else if(s[i]==p[j]) return dp[i][j] = fun(s, p, i-1, j-1, dp);
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n1 = s.length(), n2 = p.length();
        vector<vector<int>>dp(n1+1, vector<int>(n2+1, -1));
        return fun(s, p, n1-1, n2-1, dp);
    }
};