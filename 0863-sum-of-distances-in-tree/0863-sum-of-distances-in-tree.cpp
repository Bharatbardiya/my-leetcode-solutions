class Solution {
public:
    pair<int,int>dfs(vector<vector<int>>&adj, int src, int pr, vector<pair<int,int>>&dp){
        
        pair<int,int> ans = {0,1};
        for(auto u : adj[src]){
            if(u!=pr){
                pair<int,int> pr = dfs(adj, u, src, dp);
                ans.first += (pr.first+pr.second);
                ans.second += pr.second;
            }
        }
        return dp[src] = ans;
    }
    void dfs2(vector<vector<int>>&adj, int src, int pr, vector<pair<int,int>>&dp, vector<pair<int,int>>&ans){
        if(src!=0){
            ans[src] = dp[src];
            int nodes = ans[pr].second - dp[src].second; // 5
            int sums = ans[pr].first - dp[src].second - dp[src].first; // 7
            ans[src].first += (sums + nodes);
            ans[src].second += nodes;
        }

        for(auto u : adj[src]){
            if(u!=pr){
                dfs2(adj, u, src, dp, ans);
            }
        }

    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(n);
        for(auto edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<pair<int,int>>dp(n);
        dp[0] = dfs(adj, 0, -1, dp);
        // for(auto pr : dp){
        //     cout<<pr.first<<","<<pr.second<<endl;
        // }
        vector<pair<int,int>>ans(n);
        ans[0] = dp[0];
        dfs2(adj, 0, -1, dp, ans);

        vector<int>Answer(n);
        for(int i = 0; i<n; i++) Answer[i] = ans[i].first;
        return Answer;
    }
};