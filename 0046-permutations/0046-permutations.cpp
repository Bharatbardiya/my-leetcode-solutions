class Solution {
public:
    void fun(vector<int>&nums, int i, vector<vector<int>>&permutations){
        if(i==nums.size()){
            permutations.push_back(nums);
        }
        for(int j = i; j<nums.size(); j++){
            swap(nums[j], nums[i]);
            fun(nums, i+1, permutations);
            swap(nums[j], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>permutations;
        fun(nums, 0, permutations);
        return permutations;
    }
};