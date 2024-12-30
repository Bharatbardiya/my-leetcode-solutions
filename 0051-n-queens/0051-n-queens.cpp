class Solution {
public:
    bool isSafe(vector<string>&curr, int x, int y){
        int n = curr.size();
        for(int i = 0; i<=x; i++){
            if(curr[i][y]=='Q') return false;
        }
        int i = x, j = y;
        while(i>=0 and j>=0){
            if(curr[i][j]=='Q') return false;
            i--; j--;
        }
        i = x, j = y;
        while(i>=0 and j<n){
            if(curr[i][j]=='Q') return false;
            i--; j++;
        }
        return true;
    }
    void explore(int n, int i, int j, vector<string>&curr, vector<vector<string>>&ans){
        if(i==n){
            ans.push_back(curr);
            return;
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
        
        vector<vector<string>>Answer;
        vector<string>curr(n, string(n,'.'));
        explore(n, 0, 0, curr, Answer);
        return Answer;
    }
};