class Solution {
public:
    int houseRob1(vector<int>&nums, int l, int r){
        
        vector<int>dp(r+1,-1);
        dp[l] = nums[l];
        for(int i = l+1; i<=r; i++){
            int temp = 0;
            if(i>l+1) temp = dp[i-2];
            dp[i] = max(dp[i-1], temp+nums[i]);
        }
        return dp[r];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        return max(houseRob1(nums, 0,n-2), houseRob1(nums, 1, n-1));
    }
};