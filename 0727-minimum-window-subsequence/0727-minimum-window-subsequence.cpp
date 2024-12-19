class Solution {
public:
    int fun(string &s1, string &s2, int i, int j, vector<vector<int>>&dp){
        if(i<0){
            if(j<0) return 0;
            return INT_MAX;
        }
        if(j<0) return 0;
        // cout<<i<<","<<j<<endl;
        if(dp[i][j]!=-1) return dp[i][j];
        int jj = j;
        if(s1[i]==s2[j]) jj--;
        
        int val = fun(s1, s2, i-1, jj, dp);
        if(val==INT_MAX) return dp[i][j] = val;
        return dp[i][j] = 1+val;
    }

    string minWindow(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        
        int ind = -1, len = INT_MAX;
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));

        for(int i = n-1; i>=m-1; i--){
            int t = fun(s1, s2, i, m-1, dp);
            if(t<=len){
                ind = i;
                len = t;
            }
        }
        
        if(len==INT_MAX) return "";
        return s1.substr(ind-len+1, len);
    }
};