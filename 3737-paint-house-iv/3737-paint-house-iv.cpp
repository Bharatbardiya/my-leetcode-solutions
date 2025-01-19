class Solution {
    long long fun(int i, int j, int pr1, int pr2, vector<vector<int>>&cost, vector<vector<vector<long long>>>&dp){
        // int n = cost.size();
        if(i<0) return 0;
        if(dp[i][pr1][pr2]!=-1) return dp[i][pr1][pr2];

        long long ans = 1e16;
        for(int k = 0; k<3; k++){
            for(int l = 0; l<3; l++){
                if(k!=pr1 and l!=pr2 and l!=k){
                    long long temp = cost[i][k];
                    temp+=cost[j][l];
                    ans = min(ans, temp+fun(i-1, j+1, k, l, cost, dp));
                }
            }
        }
        // cout<<"ans = "<<ans<<endl;
        return dp[i][pr1][pr2] = ans;
    }
public:
    long long minCost(int n, vector<vector<int>>& cost) {
        
        int j = n/2;
        int i = j-1;
        
        long long ans = 1e16;

        vector<vector<vector<long long>>>dp(n+1, vector<vector<long long>>(3, vector<long long>(3, -1)));

        for(int k = 0; k<3; k++){
            for(int l = 0; l<3; l++){
                if(k!=l){
                    ans = min(ans,cost[i][k]+cost[j][l]+fun(i-1,j+1, k, l, cost, dp));
                }
            }
        }
        return ans;
    }
};