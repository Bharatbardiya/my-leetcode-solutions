class Solution {
public:
    bool isPossible(vector<int>&weights, int days, int m){
        int t = m;
        for(int i = 0; i<weights.size(); i++){
            t-=weights[i];
            if(t<0){
                days--;
                t = m-weights[i];
            }
        }
        days--;
        return days>=0;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int ans = 1e9;
        int l = 0 , r = 1e9;
        for(int x : weights) l = max(l,x);
        while(l<=r){
            int m  = (l+r)/2;
            bool f = isPossible(weights, days, m);
            if(f){
                ans = m;
                r = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
};