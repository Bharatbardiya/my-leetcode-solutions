class DetectSquares {
public:
    map<int,set<int>>mp1;
    map<pair<int,int>, int>mp2;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        mp1[point[0]].insert(point[1]);
        mp2[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        // for(auto pr : mp1){
        //     cout<<pr.first<<": ";
        //     for(auto x : pr.second){
        //         cout<<x<<",";
        //     }
        //     cout<<endl;
        // }
        // for(auto pr : mp2){
        //     cout<<pr.first.first<<","<<pr.first.second<<": "<<pr.second<<"),  ";
        // }
        // cout<<endl;
        int x = point[0], y = point[1];
        int Answer = 0;
        for(auto val : mp1[x]){
            int d = y-val;
            // cout<<"d = "<<d<<"val = "<<val<<endl;
            if(d!=0){
                pair<int,int> p1 = {x,y}, p2 = {x, val};
                pair<int,int> p3 = {x+d, y}, p4 = {x+d, val};
                int ans1 = 1, ans2 = 1;
                vector<pair<int,int>>vpr = {p2,p3,p4};
                for(auto pr : vpr){
                    if(mp2.find(pr)!=mp2.end()) ans1 = ans1*mp2[pr];
                    else ans1 = 0;
                }
                // for(auto pr : vpr){
                //     cout<<pr.first<<","<<pr.second<<"),";
                // }
                // cout<<endl;


                pair<int,int>p5 = {x-d, y}, p6 = {x-d, val};
                vpr = {p2,p5,p6};
                for(auto pr : vpr){
                    if(mp2.find(pr)!=mp2.end()) ans2 = ans2*mp2[pr];
                    else ans2 = 0;
                }
                // for(auto pr : vpr){
                //     cout<<pr.first<<","<<pr.second<<"),";
                // }
                // cout<<endl<<endl;
                // cout<<"ans1 = "<<ans1<<", ans2 = "<<ans2<<endl;
                Answer += (ans1+ans2);
            }
        }
        return Answer;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */