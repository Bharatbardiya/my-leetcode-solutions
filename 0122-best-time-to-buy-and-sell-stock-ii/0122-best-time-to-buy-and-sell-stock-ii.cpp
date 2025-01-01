class Solution {
public:
    int fun(vector<int>&prices, int i, bool buy, vector<vector<int>>&dp){
        if(i==0){
            if(buy) return -prices[i];
            else return 0;
        }
        if(dp[i][buy]!=-1) return dp[i][buy];
        int val1 = fun(prices, i-1, buy, dp), val2 = 0;
        if(buy){
            val2 = -prices[i] + fun(prices, i-1, false, dp);
        } else{
            val2 = prices[i] + fun(prices, i-1, true, dp);
        }
        return dp[i][buy] = max(val1, val2);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, -1));
        return fun(prices, n-1, false, dp);
    }
};