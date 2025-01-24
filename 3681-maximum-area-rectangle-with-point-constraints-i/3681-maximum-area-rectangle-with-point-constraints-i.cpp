class Solution {
public:
    bool pointConstraints(pair<int,int>&p1, pair<int,int>&p2, pair<int,int>&p3, pair<int,int>&p4, vector<vector<int>>&points){
        set<pair<int,int>>st = {p1, p2, p3, p4};
        
        for(auto v : points){
            pair<int,int>p = {v[0], v[1]};
            if(st.find(p)==st.end()){
                if((v[0]>=p1.first and v[0]<=p2.first and v[1]>=p1.second and v[1]<=p2.second)){
                    return false;
                }
            }
        }
        return true;
    }
    int maxRectangleArea(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end());
        set<pair<int,int>>st;
        int n = points.size();

        for(int i = 0; i<n; i++){
            st.insert({points[i][0], points[i][1]});
        }
        int area = 0;
        for(int i = 0; i<n; i++){
            pair<int,int>p1 = {points[i][0], points[i][1]};
            
            for(int j = i+3; j<n; j++){
                pair<int,int>p2 = {points[j][0], points[j][1]};
                if(p1.first!=p2.first and p1.second!=p2.second){
                    pair<int,int>p3 = {p1.first, p2.second};
                    pair<int,int>p4 = {p2.first, p1.second};
                    if(st.find({p3.first,p3.second})!=st.end() and st.find({p4.first,p4.second})!=st.end()){
                        if(pointConstraints(p1,p2,p3,p4, points)){
                            area = max(area, (p2.first-p1.first)*(p2.second-p1.second));
                        }
                        
                    }
                }
            }
        }
        return area==0?-1:area;
    }
};