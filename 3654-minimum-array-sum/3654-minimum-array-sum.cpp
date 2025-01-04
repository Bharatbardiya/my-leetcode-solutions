class Solution {
public:
    int explore(vector<int>&nums, int k, int op1, int op2, int i, vector<vector<vector<int>>>&dp){
        if(i<0) return 0;
        
        if(dp[i][op1][op2]!=-1) return dp[i][op1][op2];

        int val1 = nums[i] + explore(nums, k, op1, op2, i-1,dp);
        if(op1>0){
            int t = ceil(nums[i]/2.0);
            val1 = min(val1 ,  t + explore(nums, k, op1-1, op2, i-1, dp));
        }
        if(op2>0 and nums[i]>=k){
            val1 = min(val1, nums[i]-k + explore(nums, k, op1, op2-1, i-1, dp));
        }
        
        if(op1>0 and op2>0){
            int val4 = ceil(nums[i]/2.0)-k;
            if(val4>=0){
                val4 += explore(nums, k, op1-1, op2-1, i-1,dp);
                val1 = min(val1,val4);
            }
            if(nums[i]>=k){
                int val5 = ceil((nums[i]-k)/2.0);
                val5 += explore(nums, k, op1-1, op2-1, i-1,dp);
                val1 = min(val5, val1);
            }
        }
        return dp[i][op1][op2] = val1;
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(op1+1, vector<int>(op2+1, -1)));
        return explore(nums, k, op1, op2, n-1, dp);
    }
};