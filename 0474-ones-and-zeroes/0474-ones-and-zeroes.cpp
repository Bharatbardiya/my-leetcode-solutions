class Solution {
public:
    int fun(vector<pair<int,int>>&vpr, int i, int m, int n, vector<vector<vector<int>>>&dp){
        if(m<0 or n<0) return -1000000;
        else if(i<0 or (m==0 and n==0)) return 0;
        
        if(dp[m][n][i]!=-1) return dp[m][n][i];
        return dp[m][n][i] = max(fun(vpr, i-1, m,n, dp),1+fun(vpr, i-1, m-vpr[i].first, n-vpr[i].second, dp));
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>vpr;

        for(auto s : strs){
            int zeros = 0, ones = 0;
            for(auto c : s){
                if(c=='0') zeros++;
            }
            ones = s.length()-zeros;
            vpr.push_back({zeros,ones});
        }
        int size = vpr.size();
        vector<vector<vector<int>>>dp(m+1, vector<vector<int>>(n+1, vector<int>(size+1,-1)));
        int val = fun(vpr, size-1, m, n, dp);
        return val>0?val:0;
    }
};