class Solution {
public:
    bool canConstruct(string s, int k) {
        
        vector<int>feq(26,0);
        for(auto c : s) feq[c-'a']++;
        int odds = 0;
        for(auto x : feq){
            if(x%2!=0) odds++;
        }
        return (odds<=k) and s.length()>=k;
    }
};