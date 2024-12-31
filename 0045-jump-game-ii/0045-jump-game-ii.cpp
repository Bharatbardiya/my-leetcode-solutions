class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int curr = 0, ans = 0, currend = 0;
        for(int i = 0; i<n-1; i++){
            curr = max(curr, nums[i]+i);
            if(i==currend){
                currend = curr;
                ans++;
            }
        }
        return ans;
    }
};