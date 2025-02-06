class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto x : nums){
            mp[x]++;
        }
        vector<pair<int,int>>vp;
        // [1,1,1,2,2,3]
        // {1->3, 2->2, 3->1}
        for(auto pr : mp){
            vp.push_back({pr.second, pr.first});
        }
        // {{3,1}, {2,2}, {1,3}}

        sort(vp.rbegin(), vp.rend());
        // {{3,1}, {2,2}, {1,3}}
        vector<int>ans;

        for(int i = 0; i<k; i++){
            ans.push_back(vp[i].second);
        }
        return ans;
    }
};