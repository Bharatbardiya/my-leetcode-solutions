class Solution {
public:
    int fun(vector<int>&prices, int i, bool buy, vector<vector<int>>&dp){
        if(i>=prices.size()) return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            return dp[i][buy] = max(fun(prices, i+1, buy, dp), -prices[i]+fun(prices, i+1, false, dp));
        }
        return dp[i][buy] = max(fun(prices, i+1, buy, dp), prices[i]+fun(prices, i+2,true, dp));
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2,-1));
        return fun(prices, 0, true, dp);
    }
};