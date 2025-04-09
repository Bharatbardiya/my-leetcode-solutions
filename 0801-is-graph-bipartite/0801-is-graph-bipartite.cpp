class Solution {
public:
    bool dfs(vector<vector<int>>&graph, vector<char>&color, int s){
        
        for(auto u : graph[s]){
            if(color[u]=='#'){
                if(color[s]=='w'){
                    color[u] = 'b';
                }
                else color[u] = 'w';
                bool f = dfs(graph, color, u);
                if (!f) return false;
            }
            if(color[u]==color[s]) return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<char>color(n, '#');

        for(int i = 0; i<n; i++){
            if(color[i]=='#'){
                color[i] = 'w';
                bool f = dfs(graph, color, i);
                if(!f) return false;
            }
        }
        return true;
    }
};