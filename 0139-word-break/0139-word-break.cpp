class Solution {
public:
    bool fun(string &s, string &curr, int i, unordered_set<string>&st, vector<vector<int>>&dp){
        if(i==s.length()){
            if(st.find(curr)!=st.end()) return true;
            return false;
        }
        int j = curr.size();
        if(dp[i][j]!=-1) return dp[i][j];
        if(st.find(curr)!=st.end()){
            string temp = "";
            if(fun(s, temp, i, st, dp)) return dp[i][j] = true;
        }
        curr.push_back(s[i]);
        if(fun(s, curr, i+1, st, dp)) return dp[i][j] = true;
        curr.pop_back();
        return dp[i][j] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        string curr = "";
        unordered_set<string>st;
        for(auto s : wordDict) st.insert(s);
        vector<vector<int>>dp(s.length()+1, vector<int>(s.length()+1, -1));
        return fun(s, curr, 0, st, dp);
    }
};