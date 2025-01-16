class Solution {
public:
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