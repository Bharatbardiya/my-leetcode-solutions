class Solution {
public:
    bool explore(string &s, vector<pair<char,char>>&vpr, int i, int j){
        int n = s.length(), m = vpr.size();
        if(i>=n){
            if(j==m) return true;
            else if(vpr[j].second=='*') return explore(s,vpr,i,j+1);
            return false;
        }
        if(j>=m) return false;

        if(vpr[j].second=='*'){
            if(explore(s, vpr, i, j+1)) return true;
            if(vpr[j].first=='.') return explore(s, vpr, i+1, j);
            else if(vpr[j].first==s[i]) return explore(s, vpr, i+1, j);
            else return false;
        }
        if(vpr[j].first=='.') return explore(s, vpr, i+1, j+1);
        else if(vpr[j].first==s[i]) return explore(s, vpr, i+1, j+1);
        return false;
    }

    vector<pair<char,char>>convertPattern(string &s){
        vector<pair<char,char>>vpr;
        for(int i = 0; i<s.length(); i++){
            if(s[i]=='*'){
                auto pr = vpr.back();
                vpr.pop_back();
                pr.second = '*';
                vpr.push_back(pr);
            }
            else{
                vpr.push_back({s[i], '#'});
            }
        }
        return vpr;
    }
    bool isMatch(string s, string p) {
        vector<pair<char,char>>vpr = convertPattern(p);
        return explore(s,vpr, 0,0);
    }
};