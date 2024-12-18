class Solution {
public:
    int fun(vector<int>&nums, int target, int i, vector<vector<int>>&dp, int limit){
        if(i<0){
            return target==0;
        }
        // cout<<target<<","<<limit<<", "<<dp[0].size()<<endl;
        if(dp[i][target+limit]!=-1) return dp[i][target+limit];

        int plus = fun(nums, target+nums[i], i-1, dp, limit);
        int minus = fun(nums, target-nums[i], i-1, dp, limit);
        return dp[i][target+limit] = plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto x : nums) sum+=x;
        sum = 2*sum+2*abs(target);
        int limit = sum/2;
        vector<vector<int>>dp(nums.size()+1, vector<int>(sum+2,-1));
        return fun(nums, target, nums.size()-1, dp, limit);
    }
};