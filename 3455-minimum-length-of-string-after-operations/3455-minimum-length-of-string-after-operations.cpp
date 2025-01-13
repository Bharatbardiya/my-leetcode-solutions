class Solution {
public:
    int minimumLength(string s) {
        int ans = 0;
        vector<int>feq(26,0);
        for(auto c : s){
            feq[c-'a']++;
        }
        for(auto x : feq){
            if(x>0){
                if(x%2==0) ans+=2;
                else ans+=1;
            }
        }
        return ans;
    }
};