class Solution {
public:
    void fun(vector<int>&arr, vector<vector<int>>&ans, vector<int>&curr, int target, int i){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(target<0 or i==arr.size()) return;

        curr.push_back(arr[i]);
        fun(arr, ans, curr, target-arr[i], i);
        curr.pop_back();

        while(i<arr.size()-1 and arr[i]==arr[i+1]) i+=1;
        fun(arr, ans, curr, target, i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>curr;
        fun(candidates, ans, curr, target, 0);
        return ans;
    }
};