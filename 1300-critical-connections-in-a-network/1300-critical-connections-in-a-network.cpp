class Solution {
public:

    int dfs(vector<vector<int>>&adj, int src, vector<int>&disc, vector<int>&low,  int p, int &count, vector<vector<int>>&bridges){
        if(disc[src]!=-1) return low[src];
        
        count++;
        disc[src] = count;
        low[src] = count;
        for(auto u : adj[src]){
            if(u!=p){
                low[src] = min(low[src], dfs(adj, u, disc, low, src, count, bridges));
            }
        }
        if(p!=-1 and low[src]>disc[p]) bridges.push_back({p, src});
        return low[src];

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections){
        vector<vector<int>>adj(n);
        for(auto edge : connections){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            
        }

        vector<vector<int>>bridges;
        vector<int>disc(n, -1);
        vector<int>low(n, 1e9);
        int count = 0;
        dfs(adj, 0, disc, low, -1, count, bridges);
        // for(auto x: low){
        //     cout<<x<<",";
        // }
        // cout<<endl;
        // for(auto x: disc){
        //     cout<<x<<",";
        // }
        return bridges;
    }
};