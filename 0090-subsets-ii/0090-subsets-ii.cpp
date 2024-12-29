class Solution {
public:
    void explore(vector<int>&nums, int i, vector<vector<int>>&ans, vector<int>&curr){
        if(i==nums.size()){
            ans.push_back(curr);
            return;
        }
        int val = nums[i];
        curr.push_back(nums[i]);
        explore(nums, i+1, ans, curr);
        curr.pop_back();
        while(i<nums.size() and nums[i]==val) i++;
        explore(nums, i, ans, curr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>curr;

        explore(nums, 0, ans, curr);
        return ans;
    }
};