class Solution {
public:
    bool mergePossible(int sum, int val){
        while(sum>0 or val>0){
            if(sum&1==1 and val&1==1) return false;
            sum/=2;
            val/=2;
        }
        return true;
    }

    int longestNiceSubarray(vector<int>& nums) {
        int left = -1, right = 1, n = nums.size();
        int sum = nums[0], ans = 1;

        while(left<right and right<n){
            if(mergePossible(sum, nums[right])){
                sum = (sum|nums[right]);
                ans = max(ans, right-left);
                right++;
            }
            else{
                left++;
                sum = (sum^nums[left]);
            }
        }
        return ans;
    }
};