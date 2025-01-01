class Solution {
public:
    int _minDistance(string &word1, string &word2, int i, int j, vector<vector<int>>&dp){
        if(i<0 and j<0) return 0;
        else if(i<0 or j<0) return max(i,j)+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return dp[i][j] = _minDistance(word1, word2, i-1, j-1, dp);
        return dp[i][j] = 1+min(_minDistance(word1, word2, i-1, j, dp), 
        min(_minDistance(word1, word2, i, j-1, dp), _minDistance(word1, word2, i-1, j-1, dp)));
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        if(n1==0 or n2==0) return max(n1,n2);
        vector<vector<int>>dp(n1+1, vector<int>(n2+1, -1));
        return _minDistance(word1, word2, n1-1, n2-1, dp);
    }
};