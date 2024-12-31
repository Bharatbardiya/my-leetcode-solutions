class Solution {
public:
    int maxSum(vector<int>&pre, int i, int k, int need, vector<vector<int>>&dp){
        if(need==0) return 0;
        if(i<=0) return 0;

        if(dp[need][i]!=-1) return dp[need][i];
        int val = maxSum(pre, i-1, k, need, dp);
        if(i-k>=0){
            int val2 = (pre[i]-pre[i-k]) + maxSum(pre, i-k, k, need-1, dp);
            val = max(val,val2);
        }
        return dp[need][i] = val;
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pre(n+1);
        vector<vector<int>>dp(4, vector<int>(n+1, -1));
        for(int i = 0; i<n; i++){
            pre[i+1] = pre[i]+nums[i];
        }
        int maxi = maxSum(pre, n, k, 3, dp);
        // for(auto v : dp){
            // for(auto x : v) cout<<x<<" ";
            // cout<<endl;
        // }
        vector<int>ans;
        int count = 3;
        int i = n;
        while(i>0 and count>0){
            if(dp[count][i]==dp[count][i-1]) i--;
            else{
                ans.push_back(i-k);
                count--; i = i-k;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};