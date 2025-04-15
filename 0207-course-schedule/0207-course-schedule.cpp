class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>adj(n);
        vector<int>degree(n);

        for(auto edge : prerequisites){
            int v = edge[0], u = edge[1];
            adj[u].push_back(v);
            degree[v]++;
        }

        queue<int>q;
        for(int i = 0; i<n; i++){
            if(degree[i]==0) q.push(i);
        }

        while(q.size()>0){
            int u = q.front();
            q.pop();
            for(auto v : adj[u]){
                degree[v]--;
                if(degree[v]==0) q.push(v);
            }
        }
        for(int i = 0; i<n; i++){
            if(degree[i]>0) return false;
        }

        return true;
    }
};