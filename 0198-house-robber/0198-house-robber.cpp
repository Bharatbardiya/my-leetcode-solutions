class Solution {
public:
    int fun(vector<int>&nums, int i, vector<int>&dp){
        if(i<0) return 0;
        if(i==0) return nums[i];
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(fun(nums, i-1, dp), nums[i]+fun(nums, i-2, dp));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1);
        dp[0] = nums[0];
        
        for(int i = 1; i<n; i++){
            int temp = 0;
            if(i>1) temp = dp[i-2];
            dp[i] = max(dp[i-1], temp+nums[i]);
        }
        return dp[n-1];
    }
};