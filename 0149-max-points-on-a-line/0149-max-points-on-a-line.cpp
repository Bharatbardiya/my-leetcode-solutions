class Solution {
public:
    int gcd(int x, int y){
        if(x<y) return gcd(y,x);
        if(y==0) return x;
        return gcd(y, x%y);
    }

    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = min(2, (int)points.size());
        // (y1-y2)/(x1-x2) = (y2-y3)/(x2-x3)
        // => (y1-y2)*(x2-x3) = (y2-y3)*(x1-x2)
        for(int i = 0; i<n; i++){
            int x1 = points[i][0], y1 = points[i][1];
            // int temp = 0;
            map<pair<int,int>,int>mp;
            for(int j = i+1; j<n; j++){
                int x2 = points[j][0], y2 = points[j][1];
                int top = (y1-y2), bottom = (x1-x2);
                if(bottom<0){
                    top *= -1;
                    bottom *= -1;
                }
                if(top==0){
                    bottom = 0;
                }
                else if(bottom==0){
                    top=INT_MAX; bottom=INT_MAX;
                }
                int my_gcd = gcd(abs(top), abs(bottom));
                if(my_gcd>0 and top!=INT_MAX) top /= my_gcd;
                if(my_gcd>0 and top!=INT_MAX) bottom /= my_gcd;
                mp[{top, bottom}]++;
                ans = max(ans, mp[{top, bottom}]+1);
            }

        }
        return ans;
    }
};