class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        map<int,int>mp;
        for(auto pr : meetings){
            int x = pr[0], y = pr[1];
            mp[x]++; mp[y+1]--;
        }
        int curr = 0, prev = 1;
        int ans = 0;
        for(auto pr : mp){
            if(curr==0){
                ans += (pr.first-prev);
            }
            curr += pr.second;
            if(curr == 0){
                prev = pr.first;
            }
        }
        if(days>=prev) ans += (days-prev+1);
        return ans;
    }
};