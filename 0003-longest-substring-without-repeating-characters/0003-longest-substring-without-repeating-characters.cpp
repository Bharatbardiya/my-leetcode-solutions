class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
       map<int,int>mp;
       int i = 0, ans = 0;
       for(int j = 0; j<s.length(); j++){
            if(mp.find(s[j])!=mp.end()){
                i = max(i,mp[s[j]]+1);
            }
            ans = max(ans, j-i+1);
            mp[s[j]] = j;
       }
       return ans;
    }
};