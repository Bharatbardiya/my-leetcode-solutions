class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<vector<int>>pre(n);
        vector<int>feq(26), feq2(26);

        for(int i = 0; i<n; i++){
            feq[s[i]-'a']++;
            pre[i] = feq;
        }

        set<pair<char,int>>st;

        for(int i = n-1; i>0; i--){
            if(i<n-1){
                for(int j =0; j<26; j++){
                    if(feq2[j]>0 and pre[i-1][j]>0){
                        st.insert({s[i], j});
                        // cout<<s[i]<<", "<<j<<"),";
                    }

                }
            }
            feq2[s[i]-'a']++;
        }
        return st.size();
    }
};