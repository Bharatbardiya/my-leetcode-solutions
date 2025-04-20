class Solution {
public:
    string longestPalindrome(string s) {
        
        int l = -1, r = -1, n = s.length();
        vector<vector<int>>dp(n+1, vector<int>(n+1,0));
        for(int i = 0; i<s.length(); i++){
            for(int j = 0; j<n-i; j++){
                int k = j+i;
                // cout<<j<<","<<k<<"),";
                if(j==k)
                    dp[j][k] = 1;
                else if(k==j+1 and s[k]==s[j])
                    dp[j][k] = 1;
                else if(s[j]==s[k] and dp[j+1][k-1]==1)
                    dp[j][k] = 1;

                if(dp[j][k] == 1){
                    l = j;
                    r = k;
                }
            }
            // cout<<endl;
        }
        string ans = s.substr(l, r-l+1);
        return ans;
    }
};