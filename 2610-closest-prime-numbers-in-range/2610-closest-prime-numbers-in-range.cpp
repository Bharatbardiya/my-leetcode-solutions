class Solution {
public:

    vector<bool> seive(int left, int right){
        vector<bool>prime(right+1, true);
        prime[0]=false; prime[1]=false;
        for(int i = 2; i*i<=right; i++){
            if(prime[i]){
                for(int j = 2*i; j<=right; j+=i){
                    prime[j] = false;
                }
            }
        }
        return prime;
    }
    vector<int> closestPrimes(int left, int right) {

        vector<bool> prime = seive(left, right);
        vector<int> ans = {-1,-1};
        int first = -1, second = -1;
        int diff = INT_MAX;
        for(int i = left; i<=right; i++){
            if(prime[i]==true){
                if(first==-1) first = i;
                else if(second==-1) second = i;
                else{
                    if(diff>second-first){
                        ans = {first, second};
                        diff = second-first;
                    }
                    first = second;
                    second = i;
                }
            }
        }
        if(diff>second-first) ans = {first, second};
        if(ans[1]==-1) return {-1,-1};
        return ans;
    }
};