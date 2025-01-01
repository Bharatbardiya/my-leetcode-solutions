class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int>pre(n), post(n);
        pre[0] = (s[0]=='0');
        post[n-1] = (s[n-1]=='1');
        for(int i = 1; i<n; i++){
            pre[i] = pre[i-1] + (s[i]=='0');
        }
        for(int j = n-2; j>=0; j--){
            post[j] = post[j+1] + (s[j]=='1');
        }
        // for(auto x : pre) cout<<x<<",";
        int ans = 0;
        for(int i = 0; i<n-1; i++){
            ans = max(ans, pre[i]+post[i+1]);
        }
        return ans;
    }
};