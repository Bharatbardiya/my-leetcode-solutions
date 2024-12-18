class Solution {
public:
    int fun(int amount, vector<int>&coins, int i, vector<vector<int>>&dp){
        if(i<0) return amount==0;
        if(amount<0) return 0;
        if(dp[amount][i]!=-1) return dp[amount][i];
        return dp[amount][i] = fun(amount, coins, i-1, dp) + fun(amount-coins[i], coins, i, dp);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(amount+1, vector<int>(coins.size()+1, -1));

        return fun(amount, coins, coins.size()-1, dp);
    }
};