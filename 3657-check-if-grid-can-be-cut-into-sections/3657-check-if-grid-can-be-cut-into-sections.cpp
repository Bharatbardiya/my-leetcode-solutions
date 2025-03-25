class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        map<int,pair<int,int>>mp1,mp2;

        for(auto v : rectangles){
            int x1 = v[0], y1 = v[1], x2 = v[2], y2 = v[3];
            mp1[x1].first++;
            mp1[x2].second--;
            mp2[y1].first++;
            mp2[y2].second--;
        }

        int t1 = 0, curr = 0;
        for(auto pr : mp1){
            int val1 = pr.second.first, val2 = pr.second.second;
            // cout<<pr.first<<":"<<val1<<","<<val2<<"),";
            curr += val2;
            if(val2!=0 and curr==0){
                // cout<<"||"<<pr.first<<":"<<val1<<","<<val2<<"),";
                t1++;
            }
            curr += val1;
        }
        // cout<<"t1 = "<<t1<<endl;
        if(t1>=3) return true;

        t1 = 0, curr = 0;
        for(auto pr : mp2){
            int val1 = pr.second.first, val2 = pr.second.second;
            // cout<<pr.first<<":"<<val1<<","<<val2<<"),";
            curr += val2;
            if(val2!=0 and curr==0) t1++;
            curr += val1;
        }

        if(t1>=3) return true;
        return false;
    }
};