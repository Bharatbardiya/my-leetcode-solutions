class Solution {
public:

    int countPrimes(int n) {
        if(n<=1) return 0;
        vector<bool>prime(n+1, true);
        int ans = 0;
        for(int i=2; i*i<=n; i++){
            if(prime[i]){
                for(int j = 2*i; j<=n; j+=i){
                    prime[j] = false;
                }
            }
        }
        for(int i = 2; i<n; i++){
            if(prime[i]) ans++;
        }
        return ans;
    }
};