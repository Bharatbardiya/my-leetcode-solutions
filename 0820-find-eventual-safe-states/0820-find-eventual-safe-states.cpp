class Solution {
public:
    bool dfs(vector<vector<int>>&graph, vector<bool>&vis, vector<bool>&pathvis, int s){
        if(pathvis[s]) return false;
        if(vis[s]) return true;

        vis[s] = true;
        pathvis[s] = true;

        bool flag = true;
        for(auto x : graph[s]){
            flag = flag and dfs(graph, vis, pathvis, x);
        }
        if(flag) pathvis[s] = false;
        return flag;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool>vis(n,false), pathvis(n,false);

        for(int i = 0; i<n; i++){
            if(vis[i]==false){
                dfs(graph, vis, pathvis, i);
            }
        }
        vector<int>ans;
        for(int i = 0; i<n; i++){
            if(pathvis[i]==false) ans.push_back(i);
        }
        return ans;
    }
};