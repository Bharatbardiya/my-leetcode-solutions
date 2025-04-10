class Solution {
public:
    long long fun(vector<int>&nums, int i, int k, vector<vector<long long>>&dp){
        long long sum = 0;
        long long temp = INT_MAX;
        if(k==0){
            for(int j = i; j>=0; j--) sum+=nums[j];
            return sum;
        }
        if(i<0) return temp;
        
        if(dp[i][k]!=-1) return dp[i][k];

        for(int j = i; j>=0; j--){
            sum+=nums[j];
            temp = min(temp, max(sum, fun(nums, j-1, k-1, dp)));
        }
        return dp[i][k]=temp;
    }
    int splitArray(vector<int>& nums, int k) {
        
        int curr = 0;
        int ans = 0, n = nums.size();
        vector<vector<long long>>dp(n+3, vector<long long>(k+3, -1));
        return fun(nums, nums.size()-1, k-1, dp);
    }
};