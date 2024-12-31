class Solution {
public:
    int minCost(vector<int>&days, int i, vector<int>&costs, vector<int>&dp){
        if(i>=days.size()) return 0;
        if(dp[i]!=-1) return dp[i];

        int val1 = costs[0]+minCost(days, i+1, costs, dp);
        int ind1 = upper_bound(days.begin(), days.end(), days[i]+6)-days.begin();
        int val2 = costs[1]+minCost(days, ind1, costs, dp);
        int ind2 = upper_bound(days.begin(), days.end(), days[i]+29)-days.begin();
        int val3 = costs[2]+minCost(days, ind2, costs, dp);
        return dp[i] = min(val1, min(val2,val3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1, -1);
        return minCost(days, 0, costs, dp);
    }
};