class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0], curr = nums[0];
        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i]<nums[i+1]) curr+=nums[i+1];
            else curr = nums[i+1];
            ans = max(ans, curr);
        }
        return ans;
    }
};