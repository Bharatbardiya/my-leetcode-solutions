class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]++;
        int val = 0;
        int ans = 0;

        for(auto x : nums){
            val+=x;
            if(mp.find(val-k)!=mp.end()){
                ans+=mp[val-k];
            }
            mp[val]++;
        }
        return ans;
    }
};