class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long ans = ((long long)n*(n-1))/2;
        map<int,long long>mp;
        for(int i = 0; i<n; i++){
            mp[nums[i]-i]++;
        }
        for(auto pr : mp){
            auto val = pr.second;
            ans -= (val*(val-1))/2;
        }
        return ans;
    }
};