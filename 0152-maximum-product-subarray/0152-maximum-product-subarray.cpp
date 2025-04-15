class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mini = 1, maxi = 1, ans = -1e9;
        int n = nums.size();

        for(int i = 0; i<n; i++){
            if(nums[i]<0){
                swap(maxi, mini);
            }
            if(nums[i]==0){
                mini = 1;
                maxi = 1;
                ans = max(ans, nums[i]);
            }
            else{
                mini = min(nums[i],mini*nums[i]);
                maxi = max(nums[i],maxi*nums[i]);
                ans = max(ans, maxi);
            }
        }
        return ans;
    }
};