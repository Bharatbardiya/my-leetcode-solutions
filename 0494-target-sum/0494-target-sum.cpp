class Solution {
public:
    int fun(vector<int>&nums, int target, int i){
        if(i<0){
            return target==0;
        }
        return fun(nums, target, i-1) + fun(nums, target-nums[i], i-1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0, n = nums.size();
        for(auto x : nums) sum+=x;
        if((sum+target)%2!=0) return 0;
        target = (sum+target)/2;

        return fun(nums, target, n-1);
    }
};