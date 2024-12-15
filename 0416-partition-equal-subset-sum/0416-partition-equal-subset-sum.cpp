class Solution {
public:
    bool fun(vector<int>&nums, int i, int target, vector<vector<int>>&dp){
        if(i<0) return target==0;
        if(target<0) return false;
        
        if(dp[i][target]!=-1) return dp[i][target];
        return dp[i][target] = fun(nums, i-1, target-nums[i], dp) || fun(nums, i-1, target, dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i = 0; i<n; i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int target = sum/2;
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        return fun(nums, n-1, target, dp);
    }
};