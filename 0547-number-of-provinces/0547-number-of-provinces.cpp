class Solution {
public:
    void dfs(vector<vector<int>>&adj, int s, vector<bool>&vis){
        if(vis[s]) return;
        vis[s] = true;
        for(int i = 0; i<adj.size(); i++){
            if(i!=s and adj[s][i]==1){
                dfs(adj, i, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>vis(n,false);
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(vis[i]) continue;
            dfs(isConnected, i, vis);
            ans++;
        }
        return ans;
    }
};