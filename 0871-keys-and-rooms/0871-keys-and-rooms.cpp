class Solution {
public:
    void dfs(vector<vector<int>>&rooms, vector<bool>&vis, int s){
        if(vis[s]) return;
        vis[s] = true;
        for(auto v : rooms[s]){
            dfs(rooms, vis, v);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>vis(n, false);
        dfs(rooms, vis, 0);
        for(auto x : vis) if(!x) return false;
        return true;
    }
};