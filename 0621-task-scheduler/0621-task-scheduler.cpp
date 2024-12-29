class Cmp{
    public:
    bool operator()(pair<int,int>&a, pair<int,int>&b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first>b.first;
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int>mp;
        for(auto ch : tasks) mp[ch]++;
        vector<pair<int,char>>vpr;
        for(auto pr : mp){
            vpr.push_back({pr.second, pr.first});
        }
        sort(vpr.rbegin(), vpr.rend());

        priority_queue< pair<int,int>, vector<pair<int,int>>, Cmp >pq;
        int ind = 0;
        for(auto pr : vpr){
            pq.push({ind,pr.first});
            ind++;
        }
        int ans = 0, curr = -1;
        while(pq.size()>0){
            auto pr = pq.top(); pq.pop();
            // cout<<pr.first<<","<<pr.second<<"),";
            curr = max(curr+1, pr.first);
            int temp = curr+1;
            while(pq.size()>0 and pq.top().first==curr){
                auto tpr = pq.top(); pq.pop();
                pq.push({temp, tpr.second});
                temp++;
            }
            // cout<<curr+n+1<<",";
            if(pr.second>1) pq.push({curr+n+1, pr.second-1});
        }
        return curr+1;
    }
};