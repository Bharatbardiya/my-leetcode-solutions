class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        // length = n
        for(auto x : nums){
            mp[x]++;
        } // O(n)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        // log(size)
        //{{1,3}, {2,2}, {3,1}}

        for(auto pr : mp){
            // {{2,2}, {1,3}}
            
            if(pq.size()<k){
                pq.push({pr.second, pr.first});
            }
            else{
                // pr {1,3}
                auto pr2 = pq.top(); //{1,3}
                if(pr2.first<pr.second){
                    pq.pop(); // {{2,2}}
                    pq.push({pr.second, pr.first}); // {{2,2}, {3,1}}
                    // size = k
                }
            }
        }
        // O(nlogn) = time
        // O()

        
        vector<int>ans;

        while(pq.size()>0){
            ans.push_back(pq.top().second);
             pq.pop();
        }

        // O(nlogn)
        return ans;
    }
};