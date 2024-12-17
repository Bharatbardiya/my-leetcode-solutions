class Solution {
public:
    int fun(vector<int>&coins, int i, int amount, vector<vector<int>>&dp){
        if(i<0){
            if(amount==0) return 0;
            return 1e8;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int pick = INT_MAX, notpick = fun(coins, i-1, amount, dp);
        if(coins[i]<=amount){
            pick = 1+fun(coins, i, amount-coins[i], dp);
        }
        return dp[i][amount] = min(pick, notpick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1,-1));
        int val=fun(coins, n-1, amount, dp);
        return val>=1e8?-1:val;
    }
};