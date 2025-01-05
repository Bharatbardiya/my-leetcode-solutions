class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int level = 0, n = graph.size();
        queue<pair<int,int>>q;
        for(int i = 0; i<n; i++){
            q.push({i,(1<<i)});
        }
        set<pair<int,int>>st;

        while(q.size()>0){
            int k = q.size();
            for(int i = 0; i<k; i++){
                auto pr = q.front();
                q.pop();
                int u = pr.first, bitmask = pr.second;
                // cout<<u<<","<<bitmask<<","<<level<<"),";
                if(bitmask==((1<<n)-1)){
                    // cout<<"bit = "<<bitmask<<",";
                    return level;
                }
                for(auto v : graph[u]){
                    int val = (1<<v);
                    // bool exist = ((bitmask&val)==val);
                    int newbit = (bitmask|val);
                    if(st.find({v,newbit})==st.end()){
                        q.push({v, newbit}); st.insert({v,newbit});
                    }
                }
            }
            level++;
        }
        return level;
    }
};