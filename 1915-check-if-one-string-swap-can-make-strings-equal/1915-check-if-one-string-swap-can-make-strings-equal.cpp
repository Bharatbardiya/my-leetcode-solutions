class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int>feq(26);
        for(auto c : s1){
            feq[c-'a']++;
        }
        for(auto c : s2){
            feq[c-'a']--;
            if(feq[c-'a']<0) return false;
        }
        int dif = 0;
        for(int i = 0; i<s1.length(); i++){
            if(s1[i]!=s2[i]) dif++;
        }
        if(dif==0 or dif==2) return true;
        return false;
    }
};