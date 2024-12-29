class Solution {
public:
    void make_permutation(vector<int>&nums, vector<vector<int>>&ans, int i){
        if(i==nums.size()){
            ans.push_back(nums); return;
        }

        for(int j = i; j<nums.size(); j++){
            // vector<int>temp = nums;
            swap(nums[i], nums[j]);
            make_permutation(nums, ans, i+1);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>>ans;
        make_permutation(nums, ans, 0);
        return ans;
    }
};