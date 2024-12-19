class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i]<=0 or nums[i]>n) continue;
            if(nums[i]==nums[nums[i]-1]) continue;
            while(nums[i]!=i+1){
                if(nums[i]<=0 or nums[i]>n) break;
                if(nums[i]==nums[nums[i]-1]) break;
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        // for(auto x : nums) cout<<x<<" ";

        for(int i = 0; i<n; i++){
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};