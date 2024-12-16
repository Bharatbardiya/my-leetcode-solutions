class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i = 0; i<n; i++){

            pq.push({nums[i], i});
        }
        for(int i = 0; i<k; i++){
            auto pr = pq.top(); pq.pop();
            pr.first*=multiplier;
            pq.push(pr);
        }
        vector<int>ans(n);
        while(pq.size()>0){
            auto pr = pq.top(); pq.pop();
            ans[pr.second] = pr.first;
        }
        return ans;
    }
};