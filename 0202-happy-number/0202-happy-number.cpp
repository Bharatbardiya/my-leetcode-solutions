class Solution {
public:
    bool isHappy(int n) {
        //2, 4, 16, 37, 58, 25+64=98, 81+64=145, 1+16+25=42, 20, 4,
        unordered_set<int>st;
        while(n>1){
            int ans = 0;
            while(n>0){
                int rem = n%10;
                ans += (rem*rem);
                n = n/10;
            }
            if(ans==1) break;
            if(st.count(ans)) return false;
            st.insert(ans);
            n = ans;
        }
        return true;
    }
};