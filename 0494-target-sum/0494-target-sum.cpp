class Solution {
public:
    int fun(vector<int>&nums, int target, int i, map<pair<int,int>,int>&dp){
        if(i<0){
            return target==0;
        }
        if(dp.find({i,target})!=dp.end()) return dp[{i,target}];

        int plus = fun(nums, target+nums[i], i-1, dp);
        int minus = fun(nums, target-nums[i], i-1, dp);
        return dp[{i,target}] = plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto x : nums) sum+=x;
        map<pair<int,int>, int>dp;
        return fun(nums, target, nums.size()-1, dp);
    }
};