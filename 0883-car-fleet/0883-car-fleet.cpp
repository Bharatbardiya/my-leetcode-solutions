class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double>st;
        int n = position.size();
        vector<pair<int,int>>vpr;

        for(int i = 0; i<n; i++){
            vpr.push_back({position[i], speed[i]});
        }
        sort(vpr.begin(), vpr.end());

        for(int i = n-1; i>=0; i--){
            double time = (target-vpr[i].first)/(vpr[i].second*1.0);

            if(st.size()==0 or st.top()<time) st.push(time);
        }
        return st.size();
    }
};