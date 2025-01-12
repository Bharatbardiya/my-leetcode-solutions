class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto flight : flights){
            int u = flight[0], v = flight[1], w = flight[2];
            adj[u].push_back({v,w});
        }

        using vi  = vector<int>;
        vector<int>price(n,INT_MAX);
        price[src] = 0;
        
        queue<vi>q;
        q.push({0,0, src});

        while(q.size()>0){
            auto vi = q.front();
            q.pop();
            int stop = vi[0], d = vi[1], u = vi[2];
            if(u==dst or stop>k){
                continue;
            }
            for(auto v : adj[u]){
                int node = v.first, wt = v.second;
                if(price[node] > d+wt){
                    price[node] = d+wt;
                    q.push({stop+1, price[node], node});
                }
            }
        }
        return (price[dst]==INT_MAX)?-1:price[dst];
    }
};