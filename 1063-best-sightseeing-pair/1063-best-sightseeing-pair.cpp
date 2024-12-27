class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int ans = 0;
        int temp = 0;
        // 8, 2, 7, 5, 10,
        // 
        for(int i = 0; i<n; i++){
            if(i>0) ans = max(ans, temp+values[i]-i);
            temp = max(temp, values[i]+i);
            // cout<<temp<<",";
        }
        return ans;
    }
};