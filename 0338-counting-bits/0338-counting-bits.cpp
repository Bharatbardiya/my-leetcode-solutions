class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1);
       if(n==0) return dp;
       else if(n==1){
            dp[1] = 1;
            return dp;
       }
        int val = 2, count = 0;

        dp[1] = 1;
        for(int i = 2; i<=n; i++){
            if(i==val){
                count++; val = (val<<1);
            }
            int t = (i^(1<<count));
            // cout<<val<<","<<t<<","<<i<<"),";
            // cout<<count<<",";
            dp[i] = (1+dp[t]);
        }
        return dp;
    }
};