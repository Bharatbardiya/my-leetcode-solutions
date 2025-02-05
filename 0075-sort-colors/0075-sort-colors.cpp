class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = -1, j = 0, k = nums.size()-1;
        while(j<=k){
            if(nums[j]==2){
                swap(nums[j], nums[k]);
                k--;
            }
            else if(nums[j]==0){
                i++;
                swap(nums[i], nums[j]);
                j++;
            }
            else j++;
        }
        // 1,0,2
    }
};