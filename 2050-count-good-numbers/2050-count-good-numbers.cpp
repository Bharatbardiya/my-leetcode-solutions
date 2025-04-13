class Solution {
public:
    long long power(long long n){
        if(n==0) return 1;
        long long mod = 1e9+7;
        long long ans = 1;
        if(n%2!=0) ans *= 20;
        long long temp = power(n/2);
        ans = (((ans*temp)%mod)*temp)%mod;
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long mod = 1e9+7;
        if(n%2==1){
            long long t = countGoodNumbers(n-1);
            t = (t*5)%mod;
            return t;
        }
        n = n/2;
        return power(n);
    }
};