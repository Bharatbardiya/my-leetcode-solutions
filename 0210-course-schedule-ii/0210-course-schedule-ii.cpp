class Solution {
public:
    bool dfs(vector<vector<int>>&adj, vector<bool>&vis, stack<int>&st, int u, vector<bool>&pathvis){
        if(pathvis[u]) return false;
        if(vis[u]) return true;
        vis[u] = true;
        pathvis[u] = true;
        for(auto v : adj[u]){
            bool f = dfs(adj, vis, st, v, pathvis);
            if(!f) return false;
        }
        pathvis[u] = false;
        st.push(u);
        return true;
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<bool>vis(n,false);
        vector<bool>pathvis(n,false);
        vector<vector<int>>adj(n);
        for(auto pr : prerequisites){
            adj[pr[1]].push_back(pr[0]);
        }
        stack<int>st;
        for(int i = 0; i<n; i++){
            bool f = dfs(adj, vis, st, i, pathvis);
            if(!f) return {};
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};