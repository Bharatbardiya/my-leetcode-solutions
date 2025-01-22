class Solution {
public:
    int squareDist(vector<int>&p1, vector<int>&p2){
        return pow((p1[0]-p2[0]), 2) + pow((p1[1]-p2[1]), 2);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>>points = {p1, p2, p3, p4};
        sort(points.begin(), points.end());
        int dig1 = squareDist(points[0], points[3]);
        int dig2 = squareDist(points[1], points[2]);
        if(dig1!=dig2){
            return false;
        }
        int d1 = squareDist(points[0], points[1]);
        int d2 = squareDist(points[1], points[3]);
        int d3 = squareDist(points[3], points[2]);
        int d4 = squareDist(points[2], points[0]);
        // cout<<dig1<<","<<dig2<<endl;
        // cout<<d1<<","<<d2<<","<<d3<<","<<d4<<endl;
        if(d1==0 or d2 == 0 or d3 == 0 or d4 == 0) return false;
        if(d1==d2 and d2==d3 and d3==d4 and d4==d1) return true;
        return false;
    }
};