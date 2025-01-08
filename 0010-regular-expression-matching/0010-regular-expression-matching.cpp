class Solution {
public:
    bool explore(string &s, vector<pair<char,char>>&vpr, int i, int j, vector<vector<int>>&dp){
        int n = s.length(), m = vpr.size();
        if(i>=n){
            if(j==m) return true;
            else if(vpr[j].second=='*') return explore(s,vpr,i,j+1, dp);
            return false;
        }
        if(j>=m) return false;

        if(dp[i][j]!=-1) return dp[i][j];
        if(vpr[j].second=='*'){
            if(explore(s, vpr, i, j+1, dp)) return dp[i][j] = true;
            if(vpr[j].first=='.') return dp[i][j] = explore(s, vpr, i+1, j, dp);
            else if(vpr[j].first==s[i]) return dp[i][j] = explore(s, vpr, i+1, j, dp);
            else return dp[i][j] = false;
        }
        if(vpr[j].first=='.') return dp[i][j] = explore(s, vpr, i+1, j+1, dp);
        else if(vpr[j].first==s[i]) return dp[i][j] = explore(s, vpr, i+1, j+1, dp);
        return dp[i][j] = false;
    }

    vector<pair<char,char>>convertPattern(string &s){
        vector<pair<char,char>>vpr;
        for(int i = 0; i<s.length(); i++){
            if(s[i]=='*'){
                auto pr = vpr.back();
                vpr.pop_back();
                pr.second = '*';
                vpr.push_back(pr);
            }
            else{
                vpr.push_back({s[i], '#'});
            }
        }
        return vpr;
    }
    bool isMatch(string s, string p) {
        vector<pair<char,char>>vpr = convertPattern(p);
        int n = s.length(), m = vpr.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return explore(s,vpr, 0,0, dp);
    }
};