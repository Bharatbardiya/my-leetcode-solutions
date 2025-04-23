class Solution {
public:
    int countLargestGroup(int n) {
        map<int,int>mp;
        for(int i = 1; i<=n; i++){
            int t = 0, val = i;
            while(val>0){
                t += (val%10);
                val = (val/10);
            }
            mp[t]++;
        }

        int sum = 0, ans = 0;
        for(auto pr : mp){
            if(sum<pr.second){
                sum = pr.second;
                ans = 1;
            }
            else if(sum==pr.second) ans++;
        }
        return ans;
    }
};