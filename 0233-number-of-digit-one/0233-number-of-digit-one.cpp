class Solution {
public:
    int countDigitOne(int n) {
        long long t = 10;
        int ans = 0;
        long long N = n;
        while(t/10<=N){
            long long tt = t/10;
            int temp = (N/t)*tt;
            if(N%t!=0){
                long long rem = N%t;
                rem = rem - (tt-1);
                if(rem>0) temp+=min(rem, tt);
            }
            // printf("%d, %d, %d, %d\n",N,tt,t,temp);
            ans+=temp;
            t*=10;
        }
        return ans;
    }
};