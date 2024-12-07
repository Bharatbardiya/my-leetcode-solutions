class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>adj(n);
        vector<int>og(n);
        queue<int>q;
        
        for(int i = 0; i<n; i++){
            for(auto x : graph[i]){
                adj[x].push_back(i);
            }
            og[i] = graph[i].size();
            if (og[i]==0) q.push(i);
        }
        
        while(q.size()>0){
            int i = 0;
            int u = q.front();
            q.pop();
            for(auto x : adj[u]){
                og[x]--;
                if(og[x]==0){
                    q.push(x);
                }
            }
        }
        vector<int>ans;
        for(int i = 0; i<n; i++){
            if(og[i]==0) ans.push_back(i);
        }
        return ans;
    }
};