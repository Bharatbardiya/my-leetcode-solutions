class Solution {
public:
    int fun(vector<int>&nums, int i, int prev, vector<vector<int>>&dp){
        if(i==nums.size()) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];

        int v1 = fun(nums, i+1, prev, dp);
        int v2 = 0;
        if(prev==-1 or nums[prev]<nums[i]){
            v2 = 1 + fun(nums, i+1, i, dp);
        }
        return dp[i][prev+1] = max(v1, v2);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return fun(nums, 0, -1, dp);

    }
};