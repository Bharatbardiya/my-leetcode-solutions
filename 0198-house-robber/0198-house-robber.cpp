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
        vector<int>dp(n+1,-1);
        return fun(nums, nums.size()-1, dp);
    }
};