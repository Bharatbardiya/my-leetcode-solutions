class Solution {
public:
    void explore(vector<int>&candidates, int target, int i, vector<vector<int>>&ans, vector<int>&curr){
        if(target==0){
            ans.push_back(curr); return;
        }
        if(i<0){
            return;
        }

        if(candidates[i]<=target){
            curr.push_back(candidates[i]);
            explore(candidates, target-candidates[i], i-1, ans, curr);
            curr.pop_back();
        }
        int val = candidates[i];
        while(i>=0 and val==candidates[i]) i--;
        explore(candidates, target, i, ans, curr);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>curr;
        
        explore(candidates, target, candidates.size()-1, ans, curr);
        return ans;
    }
};