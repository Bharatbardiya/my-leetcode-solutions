class Solution {
public:
    bool dfs(vector<vector<int>>&graph, vector<char>&color, int s, char prev){
        
        if(color[s]!='#'){
            return prev!=color[s];
        }
        if(color[s]=='#'){
            if(prev=='a') color[s] = 'b';
            else color[s] = 'a';
        }
        for(auto u : graph[s]){
            bool f = dfs(graph, color, u, color[s]);
            if(!f) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<char>color(n, '#');

        for(int i = 0; i<n; i++){
            if(color[i]=='#'){
                bool f = dfs(graph, color, i, 'a');
                if(!f) return false;
            }
        }
        return true;
    }
};