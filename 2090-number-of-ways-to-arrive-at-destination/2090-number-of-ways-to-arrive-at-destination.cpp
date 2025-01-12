class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        int mod = 1e9+7;
        for(auto road : roads){
            int u = road[0], v = road[1];
            adj[u].push_back({v, road[2]});
            adj[v].push_back({u, road[2]});
        }
        using prii = pair<long long,long long>;
        vector<long long>dist(n, 1e15);
        vector<long long>ways(n, 0);
        priority_queue<prii, vector<prii>, greater<prii>>pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});

        while(pq.size()>0){
            int node = pq.top().second;
            long long dis = pq.top().first;
            pq.pop();
            // if(dis>dist[node]) continue;
            for(auto v : adj[node]){
                int adjNode = v.first, wt = v.second;
                
                if(dist[adjNode]>(dis+wt)){
                    ways[adjNode] = ways[node];
                    dist[adjNode] = dis+wt;
                    pq.push({dis+wt, adjNode});
                }
                else if(dist[adjNode]==(dis+wt)){
                    ways[adjNode] = (ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};

