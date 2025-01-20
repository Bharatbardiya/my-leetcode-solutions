class Solution {
public:
    int fun(vector<int>&nums, int l, int r, int mul1, int mul2, vector<vector<int>>&dp){
        if(l>r) return 0;
        if(l==r) return nums[l]*mul1*mul2;
        
        if(dp[l][r]!=-1) return dp[l][r];
        int ans = 0;
        for(int i = l; i<=r; i++){
            int curr = nums[i]*mul1*mul2;
            int left = fun(nums, l, i-1, mul1, nums[i], dp);
            int right = fun(nums, i+1, r, nums[i], mul2, dp);
            ans = max(ans,curr+left+right);
        }
        return dp[l][r] = ans;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return fun(nums, 0, n-1, 1,1, dp);
    }
};