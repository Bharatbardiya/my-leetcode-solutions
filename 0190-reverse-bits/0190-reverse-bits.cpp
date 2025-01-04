class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string s ="";
        while(n>0){
            int t = (n&1);
            if(t==1) s.push_back('1');
            else s.push_back('0');
            n = (n>>1);
        }
        while(s.length()<32) s.push_back('0');
        reverse(s.begin(), s.end());
        int ans = 0;
        for(int i = 0; i<32; i++){
            if(s[i]=='1')
                ans+=(1<<i);
        }
        return ans;
    }
};