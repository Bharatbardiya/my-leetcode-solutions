class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        using ll = long long;
        priority_queue<ll, vector<ll>, greater<ll>>pq;
        
        for(auto x : nums) pq.push(x);
        int ans = 0;
        while(pq.size()>1 and pq.top()<k){
            ll mini = pq.top(); pq.pop();
            ll maxi = pq.top(); pq.pop();
            pq.push(2*mini+maxi);
            ans++;
        }
        return ans;
    }
};