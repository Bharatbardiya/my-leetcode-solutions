class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        
        set<pair<int,int>>st;
        int n = points.size();
        sort(points.begin(), points.end());

        for(auto point : points){
            st.insert({point[0], point[1]});
        }
        int ans = INT_MAX;
        for(int i = 0; i<n; i++){
            int x1 = points[i][0], y1 = points[i][1];
            for(int j = i+1; j<n; j++){
                int x2 = points[j][0], y2 = points[j][1];
                if(x1!=x2 and y1!=y2){
                    int x3 = x1, y3 = y2;
                    int x4 = x2, y4 = y1;
                    if(st.find({x3,y3})==st.end()) continue;
                    if(st.find({x4,y4})==st.end()) continue;
                    ans = min(ans, abs(x2-x1)*abs(y2-y1));
                }
            }
        }
        return ans==INT_MAX?0:ans;
    }
};