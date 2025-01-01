class Solution {
public:
    int fun(vector<int>&prices, int i, bool buy, int count, vector<vector<vector<int>>>&dp){
        if(count == 2) return 0;
        if(i==prices.size()-1){
            if(buy) return 0;
            return prices[i];
        }
        if(dp[i][buy][count]!=-1) return dp[i][buy][count];

        int val1 = fun(prices, i+1, buy, count, dp);
        int val2 = 0;
        if(buy){
            val2 = -prices[i]+fun(prices, i+1, false, count, dp);
        }
        else{
            val2 = prices[i]+fun(prices, i+1, true, count+1, dp);
        }
        return dp[i][buy][count] = max(val1,val2);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));

        return fun(prices, 0, true, 0, dp);
    }
};