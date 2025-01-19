class Solution {
public:
    long long factorial(int val){
        long long temp = 1, mod = 1e9+7;
        for(int i = 1; i<=val; i++){
            temp*=i;
            temp %=mod;
        }
        return temp;
    }
    long long Ncr(int total, int choose){
        long long mod = 1e9+7;
        if(total<choose) return 0;
        long long val1 = factorial(total), val2 = factorial(choose), val3 = factorial(total-choose);
        return (val1)/((val2*val3)%mod);
    }

    int minMaxSums(vector<int>& nums, int k) {
        
        // [1,2,3,4,5,6,7]

        int mod = 1e9+7, n = nums.size();
        sort(nums.begin(), nums.end());
        long long ans = 0;
        vector<vector<long long>> ncr(nums.size() + 1, vector<long long> (k + 1,0));
        
        ncr[0][0] = 1;
        for (int n = 1; n <= nums.size(); n++) {
            ncr[n][0] = 1;
            for (int r = 1; r <= k; r++) 
                ncr[n][r] = (ncr[n - 1][r - 1] + ncr[n - 1][r]) % mod;
        }

        for(int i = 0; i<n; i++){
            long long temp = 2*nums[i];
            int K = k-1;
            int totalMax = n-i-1;
            int totalMin = i;

            for(int j = 1; j<=K; j++){
                temp += (nums[i]*ncr[totalMax][j]);
                temp %= mod;
                temp += (nums[i]*ncr[totalMin][j]);
                temp %= mod;
            }
            ans+=temp;
            ans %=mod;
        }
        return ans;
    }
};