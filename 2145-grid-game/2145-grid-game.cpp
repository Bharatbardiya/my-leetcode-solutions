class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long mini = 1e16;
        long long val1 = 0, val2 = 0;
        for(int i = 0; i<n; i++){
            val2 += grid[0][i];
        }
        for(int i = 0; i<n; i++){
            if(i>0) val1+=grid[1][i-1];
            val2 -= grid[0][i];
            // cout<<val1<<","<<val2<<endl;
            mini = min(mini, max(val1, val2));
        }
        return mini;
    }
};