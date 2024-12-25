class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0, sum = nums[0];
        for(int i = 0; i<nums.size(); i++){
            int temp = cur+nums[i];
            if(temp>=nums[i]){
                cur = temp;
                sum = max(sum,cur);
            }
            else{
                cur = nums[i];
                sum = max(sum,cur);
            }
        }
        return sum;
    }
};