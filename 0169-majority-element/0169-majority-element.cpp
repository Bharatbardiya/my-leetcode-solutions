class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int feq = 1, val = nums[0];

        for(int i = 1; i<nums.size(); i++){
            if(nums[i]==val) feq++;
            else feq--;
            if(feq<0){
                feq = 1; val = nums[i];
            }
        }
        return val;
    }
};