class Solution {
public:
    // void dfs(vector<vector<int>>&adj, int s, vector<bool>&vis){
    //     if(vis[s]) return;
    //     vis[s] = true;
    //     for(int i = 0; i<adj.size(); i++){
    //         if(i!=s and adj[s][i]==1){
    //             dfs(adj, i, vis);
    //         }
    //     }
    // }
    class DisjointSet{
        vector<int>rank, parent;
        public:
        DisjointSet(int n){
            for(int i = 0; i<n; i++){
                parent.push_back(i);
            }
            rank.resize(n);
        }

        void _union(int x, int y){
            int pr_x = find(x), pr_y = find(y);
            if(pr_x==pr_y) return;

            if(rank[pr_x]>rank[pr_y]) parent[pr_y] = pr_x;
            else if(rank[pr_x]<rank[pr_y]) parent[pr_x] = pr_y;
            else {
                rank[pr_x]++;
                parent[pr_y] = pr_x;
            }
        }
        
        int find(int x){
            if(parent[x]==x) return x;
            return parent[x] = find(parent[x]);
        }

    };
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // vector<bool>vis(n,false);
        // int ans = 0;
        // for(int i = 0; i<n; i++){
        //     if(vis[i]) continue;
        //     dfs(isConnected, i, vis);
        //     ans++;
        // }
        // return ans;
        
        DisjointSet myst(n);

        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if(isConnected[i][j]==1){
                    myst._union(i,j);
                }
            }
        }
        unordered_set<int>st;
        for(int i = 0; i<n; i++){
            st.insert(myst.find(i));
        }
        return st.size();
    }
};