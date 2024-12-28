class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        double cur_time = 0;
        int ans = 0;
        vector<pair<int,int>>vpr;

        for(int i = 0; i<n; i++){
            vpr.push_back({position[i], speed[i]});
        }
        sort(vpr.begin(), vpr.end());

        for(int i = n-1; i>=0; i--){
            double time = (target-vpr[i].first)/(vpr[i].second*1.0);

            if(cur_time<time){
                ans++; cur_time = time;
            }
        }
        return ans;
    }
};