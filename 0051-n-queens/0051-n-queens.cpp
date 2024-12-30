class Solution {
public:
    bool isSafe(vector<string>&curr, int x, int y){
        int n = curr.size();
        for(int i = 0; i<x; i++){
            if(curr[i][y]=='Q') return false;
        }
        int i = x-1, j = y-1;
        while(i>=0 and j>=0){
            if(curr[i][j]=='Q') return false;
            i--; j--;
        }
        i = x-1, j = y+1;
        while(i>=0 and j<n){
            if(curr[i][j]=='Q') return false;
            i--; j++;
        }
        return true;
    }
    void explore(int n, int i, int j, vector<string>&curr, set<vector<string>>&ans){
        if(i==n){
            ans.insert(curr);
        }
        if(j==n) return;

        if(isSafe(curr, i, j)){
            curr[i][j] = 'Q';
            explore(n, i+1, 0, curr, ans);
            curr[i][j] = '.';
        }
        explore(n, i, j+1, curr, ans);
    }
    vector<vector<string>> solveNQueens(int n) {
        set<vector<string>>ans;
        vector<vector<string>>Answer;
        vector<string>curr(n, string(n,'.'));

        explore(n, 0, 0, curr, ans);
        // ans.push_back(curr);
        for(auto val : ans) Answer.push_back(val);
        return Answer;
    }
};