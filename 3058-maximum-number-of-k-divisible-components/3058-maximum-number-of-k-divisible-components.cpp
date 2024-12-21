class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
        if(n==1){
            return values[0]%k==0;
        }
        
        vector<int>deg(n,0);
        
        vector<vector<int>>adj(n);
        
        for(auto eg : edges){
            int u = eg[0], v = eg[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int>q;
        
        for(int i = 0; i<n; i++){
            deg[i] = adj[i].size();
            if(deg[i]==1) q.push(i);
        }
        
        vector<bool>vis(n,false);
        
        int ans = 0;
        while(q.size()!=0){
            
            int u = q.front();
            q.pop();
            vis[u] = true;
            
            bool f = false;
            if(values[u]%k==0){
                ans++;
                f = true;
            }
            
            for(auto v : adj[u]){
                if(vis[v]==false){
                    
                    deg[v]--;
                    if(!f) values[v]+=values[u];
                    
                    if(deg[v]==1){
                        q.push(v);
                    }
                }
            }
        }
        return ans;
    }
};