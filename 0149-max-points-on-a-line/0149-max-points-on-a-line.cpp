class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = min(2, (int)points.size());
        // (y1-y2)/(x1-x2) = (y2-y3)/(x2-x3)
        // => (y1-y2)*(x2-x3) = (y2-y3)*(x1-x2)
        for(int i = 0; i<n; i++){
            int x1 = points[i][0], y1 = points[i][1];
            for(int j = i+1; j<n; j++){
                int temp = 2;
                int x2 = points[j][0], y2 = points[j][1];
                for(int k = j+1; k<n; k++){
                    int x3 = points[k][0], y3 = points[k][1];

                    if((y1-y2)*(x2-x3) == (y2-y3)*(x1-x2)) temp++;
                }
                ans = max(ans, temp);
            }

        }
        return ans;
    }
};