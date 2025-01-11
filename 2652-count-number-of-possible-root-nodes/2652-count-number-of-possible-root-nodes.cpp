class Solution {
public:
    int dfs(vector<vector<int>>&adj, int src, int pr, set<pair<int,int>>&st){
        
        int ans = 0;
        if(st.count({pr, src})) ans++;
        for(auto v : adj[src]){
            if(v!=pr){
                ans+=dfs(adj, v, src, st);
            }
        }
        return ans;
    }

    void dfs2(vector<vector<int>>&adj, int src, int pr, set<pair<int,int>>&st, vector<int>&correctGuess){
        if(src!=0){
            int correct = correctGuess[pr];
            if(st.count({pr,src})) correct--;
            if(st.count({src,pr})) correct++;
            correctGuess[src] = correct;
        }
        for(auto v : adj[src]){
            if(v!=pr) dfs2(adj, v, src, st, correctGuess);
        }
    }

    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size()+1;

        vector<vector<int>>adj(n);
        for(auto edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        set<pair<int,int>>st;
        for(auto guess : guesses) st.insert({guess[0], guess[1]});
        int ans = 0;
        
        vector<int>correctGuess(n);
        correctGuess[0] = dfs(adj, 0, -1, st);
        
        dfs2(adj, 0, -1, st, correctGuess);
        for(auto x : correctGuess){
            if(x>=k) ans++;
        }
        return ans;
    }
};