class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>>adj(n);
        for(auto edge : times){
            int u = edge[0], v = edge[1], time = edge[2];
            adj[u-1].push_back({v-1,time});
        }

        vector<int>dist(n, INT_MAX);
        set<pair<int,int>>st;
        st.insert({0,k-1});
        dist[k-1] = 0;

        while(st.size()>0){
            auto it = st.begin();
            int u = it->second, dis = it->first;
            // cout<<u<<","<<dis<<endl;
            st.erase(it);

            for(auto pr : adj[u]){
                int v = pr.first,  w = pr.second;
                if(dist[u]+w < dist[v]){
                    if(dist[v]!=INT_MAX) st.erase({dist[v],v});
                    dist[v] = dist[u]+w;
                    st.insert({dist[v],v});
                }
            }
        }
        int ans = 0;
        // cout<<"int max = "<<INT_MAX<<endl;
        for(auto x : dist){
            // cout<<x<<",";
            if(x==INT_MAX) return -1;
            ans = max(ans, x);
        }
        return ans;
    }
};