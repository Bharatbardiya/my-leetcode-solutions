class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        // [6,4,8,5,2,7]
        map<int, vector<pair<int,int>>, greater<int>>mp;
        vector<int>ans(queries.size(), -1);
        int i = 0;
        for(auto query : queries){
            int q1 = query[0], q2 = query[1];
            if(q1>q2) swap(q1,q2);
            if((heights[q2] > heights[q1]) or (q1==q2)){
                ans[i] = q2; i++; continue;
            }
            mp[q2].push_back({q1, i});
            i++;
        }

        map<int,int>mp3;
        for(int i = heights.size()-1; i>=0; i--){
            int val = heights[i];
            for(auto x : mp[i]){
                // cout<<i<<","<<x.first<<"),";
                int left = heights[x.first];
                auto itr = mp3.upper_bound(left);
                if(itr!=mp3.end()){
                    int temp = itr->second;
                    ans[x.second] = temp;
                }
            }
            while(mp3.size()>0 and mp3.begin()->first<val) mp3.erase(mp3.begin());
            mp3[val] = i;
        }
        return ans;
    }
};