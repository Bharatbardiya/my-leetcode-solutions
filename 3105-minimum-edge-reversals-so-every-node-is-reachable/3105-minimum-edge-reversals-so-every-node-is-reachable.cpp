class Solution {
public:
    int dfs(int src, vector<vector<int>>& adj1, vector<vector<int>>& adj2, map<pair<int, int>, int>& dp, int pr) {

        if(dp.find({src, pr})!=dp.end()) return dp[{src, pr}];
        int temp = 0;
        for (auto v : adj1[src]) {
            if (v!=pr) {
                temp += dfs(v, adj1, adj2, dp, src);
            }
        }
        for (auto v : adj2[src]) {
            if (v!=pr) {
                temp += (1+dfs(v, adj1, adj2, dp, src));
            }
        }
        return dp[{src, pr}] = temp;
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj1(n), adj2(n);
        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            adj1[u].push_back(v);
            adj2[v].push_back(u);
        }
        vector<int> ans(n);
        map<pair<int, int>, int> dp;

        for (int i = 0; i < n; i++) {
            vector<bool> vis(n, false);
            ans[i] = dfs(i, adj1, adj2, dp, -1);
        }
        return ans;
    }
};