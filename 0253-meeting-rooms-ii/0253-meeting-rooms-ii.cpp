class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int count = 0, ans = 1;
        map<int,pair<int,int>>mp;

        for(auto interval : intervals){
            int start = interval[0], end = interval[1];
            mp[start].first++;
            mp[end].first--;
            // mp[end+1].second--;
        }
        // [0,10], [10,20]
        // 0->1, 10->1, 11->-1, 20->-1
        for(auto pr : mp){
            count += (pr.second.first);
            ans = max(ans, count);
        }
        return ans;
    }
};