class Solution {
public:
    int fun(vector<vector<int>>&vpr, int i, int m, int n, vector<vector<vector<int>>>&dp){
        if(i<0 or (m==0 and n==0)) return 0;
        
        if(dp[m][n][i]!=-1) return dp[m][n][i];
        int notpick = fun(vpr, i-1, m,n, dp);
        int pick = -1000000;
        if(m>=vpr[i][0] and n>=vpr[i][1]){
            pick = 1+ fun(vpr, i-1, m-vpr[i][0], n-vpr[i][1], dp);
        }
        return dp[m][n][i] = max(pick, notpick);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();

        vector<vector<int>>vpr(size, vector<int>(2));

        for(int i = 0; i<size; i++){
            for(auto c : strs[i]){
                vpr[i][c-'0']++;
            }
        }
        vector<vector<vector<int>>>dp(m+1, vector<vector<int>>(n+1, vector<int>(size+1, 0)));
        // int val = fun(vpr, size-1, m, n, dp);
        // return val>0?val:0;

        // for(int i = 0; i<=size; i++){
        //     dp[0][0][i] = 1;
        // }
        // for(int j = 0; i<=m; j++){
        //     for(int k = 0; k<=n; k++){
        //         dp[j][k][0] = 0;
        //     }
        // }
        for(int i = 1; i<=size; i++){
            for(int j = 0; j<=m; j++){
                for(int k = 0; k<=n; k++){
                    
                    int val2 = -100000;
                    int val1 = dp[j][k][i-1];
                    if(j>=vpr[i-1][0] and k>=vpr[i-1][1])
                        val2 = 1+dp[j-vpr[i-1][0]][k-vpr[i-1][1]][i-1];

                    dp[j][k][i] = max(val1,val2);
                }
            }
        }
        return dp[m][n][size];
    }
};