class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // map<int,int>mp;
        // for(int i = 0; i<nums.size(); i++){
        //     int x = nums[i];
        //     if(mp.find(target-x)!=mp.end()){
        //         return {mp[target-x], i};
        //     }
        //     mp[x] = i;
        // }
        // return {-1,-1};
        vector<pair<int,int>>vpr;
        for(int i = 0; i<nums.size(); i++) vpr.push_back({nums[i], i});
        vector<int>ans = {-1,-1};
        sort(vpr.begin(), vpr.end());
        int i = 0, j = nums.size()-1;
        while(i<j){
            int temp = vpr[i].first+vpr[j].first;
            if(target > temp) i++;
            else if(target < temp) j--;
            else{
                ans = {vpr[i].second,vpr[j].second};
                break;
            } 
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};