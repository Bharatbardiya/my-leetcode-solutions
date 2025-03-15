class Solution {
public:
    int fun(vector<int>&nums, int k, int i, vector<vector<int>>&dp){
        if(k==0) return 0;
        if(i<0) return INT_MAX;
        if(dp[i][k]!=-1) return dp[i][k];

        return dp[i][k] = min(max(nums[i], fun(nums, k-1, i-2, dp)), fun(nums, k, i-1, dp));
    }
    
    int possible(vector<int>&nums, int mid, int k){
        
        int i = 0;
        while(i<nums.size()){
            if(nums[i]<=mid){
                i+=2; k--;
            }
            else i++;
        }
        return k<=0;
    }
    int minCapability(vector<int>& nums, int k) {
        int left = 0, right = 1e9;
        int ans = 1e9;

        while(left<=right){
            int mid = (left+right)/2;
            if(possible(nums, mid, k)){
                ans = mid;
                right = mid-1;
            }
            else left = mid+1;
        }
        return ans;

    }
};