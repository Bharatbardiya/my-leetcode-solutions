class Solution {
public:
    int fun(vector<int>&prices, int i, bool buy, int cap, vector<vector<vector<int>>>&dp){
        if(cap==0 or i==prices.size()) return 0;

        if(dp[i][cap][buy]!=-1) return dp[i][cap][buy];
        if(buy){
            return dp[i][cap][buy] = max(fun(prices, i+1, buy, cap, dp), -prices[i]+fun(prices, i+1, false, cap, dp));
        }
        return dp[i][cap][buy] = max(fun(prices, i+1, buy, cap, dp), prices[i]+fun(prices, i+1, true, cap-1, dp));
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return fun(prices, 0, true, k, dp);
    }
};