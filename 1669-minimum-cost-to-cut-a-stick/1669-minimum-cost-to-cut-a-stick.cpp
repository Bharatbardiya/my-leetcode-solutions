class Solution {
public:
    int fun(vector<int>&cuts, int l, int r, vector<vector<int>>&dp){
        if(r==l+1) return 0;
        int ans = INT_MAX;
        int len = cuts[r]-cuts[l];

        if(dp[l][r]!=-1) return dp[l][r];
        // cout<<l<<","<<r<<"),";
        for(int i = l+1; i<r; i++){
            ans = min(ans, len+fun(cuts, l, i, dp)+fun(cuts,i,r, dp) );
        }
        return dp[l][r] = ans;
    }
		
    int minCost(int n, vector<int>& cuts) {
        vector<int>Cuts = {0};
        sort(cuts.begin(), cuts.end());
        for(auto x : cuts) Cuts.push_back(x);
        Cuts.push_back(n);

        int N = Cuts.size();
        vector<vector<int>>dp(N+1, vector<int>(N+1,-1));
        return fun(Cuts, 0, Cuts.size()-1, dp);
    }
};