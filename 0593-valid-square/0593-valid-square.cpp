class Solution {
public:
    int squareDist(vector<int>&p1, vector<int>&p2){
        return pow((p1[0]-p2[0]), 2) + pow((p1[1]-p2[1]), 2);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        int d2 = squareDist(p1,p2), d3 = squareDist(p1,p3), d4 = squareDist(p1, p4);
        // cout<<d2<<","<<d3<<","<<d4<<endl;
        if(d2!=d3 and d3!=d4 and d4!=d2) return false;
        else if(d2==d3 and d3==d4) return false;
        // int digonal = -1;
        vector<vector<int>>dig1, dig2;
        dig1.push_back(p1);
        if(d2==d4){
            // cout<<"yes";
            if(d3<=d2) return false;
            dig1.push_back(p3);
            dig2.push_back(p2);
            dig2.push_back(p4);
        }
        else if(d3==d4){
            
            if(d2<=d4) return false;
            dig1.push_back(p2);
            dig2.push_back(p3);
            dig2.push_back(p4);
        }
        else{
            if(d4<=d2) return false;
            dig1.push_back(p4);
            dig2.push_back(p2);
            dig2.push_back(p3);
        }

        // for(auto p : dig1){
        //     cout<<p[0]<<","<<p[1]<<"),";
        // }
        // cout<<endl;
        // for(auto p : dig2){
        //     cout<<p[0]<<","<<p[1]<<"),";
        // }
        // cout<<endl;


        if(squareDist(dig1[0], dig1[1])!=squareDist(dig2[0], dig2[1])) 
            return false;
        int e1 = squareDist(dig1[0], dig2[0]);
        int e2 = squareDist(dig1[0], dig2[1]);
        int e3 = squareDist(dig1[1], dig2[0]);
        int e4 = squareDist(dig1[1], dig2[1]);

        if(e1!=e2 or e2!=e3 or e3!=e4) return false;
        return true;
    }
};