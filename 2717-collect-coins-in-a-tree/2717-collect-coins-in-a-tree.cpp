class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = edges.size()+1;
        if(n<=5) return 0;
        vector<vector<int>>Tree(n);
        vector<int>degree(n);
        
        for(auto edge : edges){
            int u = edge[0], v = edge[1];
            Tree[u].push_back(v);
            Tree[v].push_back(u);
            degree[v]++; degree[u]++;
        }
        
        queue<int>q;
        vector<bool>vis(n,false);
        // int benifit = 0;
        // vector<pair<bool,int>>arr(n);

        for(int i = 0; i<n; i++){
            if(degree[i]==1){
                if(coins[i]==0){
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
        int benifit = 0;
        while(q.size()>0){
            auto node = q.front(); q.pop();
            if(degree[node]==1) benifit+=2;
            for(auto nig : Tree[node]){
                degree[nig]--;
                if(vis[nig]==false and coins[nig]==0 and degree[nig]==1){
                    vis[nig] = true;
                    q.push(nig);
                }
            }
        }
        for(int i = 0; i<n; i++){
            if(degree[i]==1 and coins[i]==1){
                q.push(i); vis[i]=true;
            }
        }
        int level = 0;
        while(q.size()>0 and level<2){
            int x = q.size();
            for(int i = 0; i<x; i++){
                int node = q.front(); q.pop();
                if(degree[node]==1) benifit+=2;
                for(auto nig : Tree[node]){
                    degree[nig]--;
                    if(vis[nig]==false and degree[nig]==1){
                        vis[nig] = true; 
                        q.push(nig);
                    }
                }
            }
            level++;
        }
        // cout<<benifit<<endl;
        return 2*(n-1)-benifit;
    }
};