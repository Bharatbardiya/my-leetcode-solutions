class Solution {
public:

    bool fun(string &s, int i, int ops, int len, int curr, char prev, vector<vector<vector<int>>>&dp){
        if(i==s.length()){
            // if(len==2){
            //     cout<<"fun = "<<curr<<","<<ops<<","<<prev<<endl;
            // }
            return curr<=len;
        }
        if(curr>len) return false;
        int Copy = curr;
        if(dp[i][ops][curr]!=-1) return dp[i][ops][Copy];
        if(ops>0){
            int copy = curr;
            char temp = s[i]=='1'?'0':'1';
            if(s[i]!=prev) copy++;
            else copy = 1;
            if(fun(s, i+1, ops-1, len, copy, temp, dp)){
                return dp[i][ops][Copy] = true;
            }
        }
        
        if(s[i]==prev) curr++;
        else curr = 1;
        return dp[i][ops][Copy] = fun(s, i+1, ops, len, curr, s[i], dp);
    }
    bool helper(string &s, int ops){
        int op1 = 0, op2 = 0;
        char t = '0';
        for(auto c : s){
            if(c==t) op1++;
            else op2++;

            if(t=='0') t = '1';
            else t = '0';
        }
        return ops>=(min(op1,op2));
    }
    bool isPossible(string &s, int len, int ops){
        int n = s.length();
        // vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(ops+1, vector<int>(len+1, -1)));
        // return fun(s, 0, ops, len, 0, '2', dp);
        // 11100111
        if(len==1){
            return helper(s, ops);
        }
        int curr = 0, prev = 0;
        while(curr<n){
            if(s[curr]!=s[prev]){
                int size = curr-prev;
                
                ops -= (size/(len+1));
                prev = curr;
            }
            // cout<<ops<<",";
            curr++;
        }
        ops -= ((curr-prev)/(len+1));
        // cout<<endl;
        return ops>=0;
    }
    int minLength(string s, int numOps) {
        // 00000
        // 10101
        int low = 1, high = s.length();
        int ans = high;
        while(low<=high){
            int mid = (low+high)/2;
            if(isPossible(s, mid, numOps)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};