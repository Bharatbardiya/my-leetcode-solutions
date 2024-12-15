class Solution {
public:
    int fun(vector<vector<int>>&matrix, int i, int j){
        int n = matrix.size();
        if(i==n) return 0;
        if(j<0 or j>=n) return INT_MAX;

        return matrix[i][j]+ 
            min(    min(fun(matrix, i+1, j-1),fun(matrix, i+1, j)), 
                    fun(matrix, i+1, j+1)
                );
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>>dp(n+1, vector<int>(n));

        for(int j = 0; j<n; j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i = 1; i<n; i++){
            
            for(int j = 0; j<n; j++){
                dp[i][j] = dp[i-1][j];
                if(j>0) dp[i][j] = min(dp[i-1][j-1], dp[i][j]);
                if(j<n-1) dp[i][j] = min(dp[i-1][j+1], dp[i][j]);
                dp[i][j] += matrix[i][j];
            }
        }
        int Answer = INT_MAX;
        for(auto x : dp[n-1]){
            Answer = min(Answer, x);
        }
        return Answer;
    }
};