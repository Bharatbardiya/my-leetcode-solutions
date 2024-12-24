class Solution {
public:
    int findDiameter(vector<vector<int>>&adj){
        int n = adj.size();
        vector<int>degree(n);
        queue<int>q;
        // vector<bool>vis(n,false);
        for(int i = 0; i<n; i++){
            auto v = adj[i];
            degree[i] = v.size();
            if(v.size()==1){
                q.push(i);
                // vis[i] = true;
            }
        }
        // for(auto x : degree) cout<<x<<" ";
        int level = 0;
        while(q.size()>1){
            int x = q.size();
            for(int i = 0; i<x; i++){
                int u = q.front();
                // cout<<u<<",";
                q.pop();
                for(auto v : adj[u]){
                    degree[v]--;
                    if(degree[v]==1) q.push(v);
                }
            }
            level++;
        }
        if(q.size()==1){
            level *=2;
        }
        else level = level*2-1;
        // cout<<endl;
        return level;
    }

    int maxHeight(vector<vector<int>>&adj, int s, int p, int&d){
        
        vector<int>heights;
        for(auto v : adj[s]){
            if(v!=p){
                int t = maxHeight(adj, v, s, d);
                heights.push_back(t);
            }
        }
        sort(heights.rbegin(), heights.rend());
        if(heights.size()==0) return 1;
        else if(heights.size()==1){
            d = max(d, heights[0]+1);
        }
        else d = max(d, heights[0]+heights[1]+1);
        
        return heights[0]+1;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> adj1(n), adj2(m);

        for(auto edge : edges1){
            int u = edge[0], v = edge[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for(auto edge : edges2){
            int u = edge[0], v = edge[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        // int x1 = findDiameter(adj1), x2 = findDiameter(adj2);
        // cout<<x1<<","<<x2<<endl;
        // return max((x1+1)/2 + (x2+1)/2 + 1, max(x1,x2));
        int d1 = 0, d2 = 0;
        maxHeight(adj1, 0, -1, d1);
        maxHeight(adj2, 0, -1, d2);
        cout<<d1<<","<<d2<<endl;
        return max(d1-1, max(d2-1, d1/2 + d2/2 + 1));
    }
};