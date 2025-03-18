class Solution {
public:
    bool fun(int n, int val){
        if(n>2*val) return false;
        if(n<=1) return true;
        if(val>n) return fun(n, val/3);
        return fun(n-val, val/3);
    }
    bool checkPowersOfThree(int n) {
        
        int val = 1;
        while(val<=n){
            val*=3;
        }
        val/=3;

        return fun(n, val);
    }
};