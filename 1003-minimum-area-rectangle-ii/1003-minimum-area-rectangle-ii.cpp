#define ll long long
class Solution {
public:
    ll squareDist(int x1, int y1, int x2, int y2){
        ll temp1 = (x1-x2), temp2 = (y1-y2);
        temp1*= (x1-x2); temp2 *= (y1-y2);
        return temp1+temp2;
    }
    double minAreaFreeRect(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end());
        int n = points.size();
        double MAX = 1e12;
        double Ans = MAX;
        for(int i = 0; i<n; i++){
            int x1 = points[i][0], y1 = points[i][1];
            
            for(int j = i+1; j<n; j++){
                int x2 = points[j][0], y2 = points[j][1];

                for(int k = j+1; k<n; k++){
                    int x3 = points[k][0], y3 = points[k][1];

                    for(int l = k+1; l<n; l++){
                        int x4 = points[l][0], y4 = points[l][1];

                        ll dig1 = squareDist(x1,y1, x4, y4);
                        ll dig2 = squareDist(x2, y2, x3, y3);
                        if(dig1!=dig2) continue;

                        ll side1 = squareDist(x1,y1, x2, y2);
                        ll side2 = squareDist(x3, y3, x4, y4);

                        ll side3 = squareDist(x1, y1, x3, y3);
                        ll side4 = squareDist(x2, y2, x4, y4);

                        if(side1!=side2 or side3!=side4) continue;

                        double length = sqrt(side1), width = sqrt(side3);
                        Ans = min(Ans, length*width);
                    }
                }
            }
        }
        return Ans==MAX?0:Ans;
    }
};