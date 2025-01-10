class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<int>universal(26);
        for(auto &s : words2){
            vector<int>feq(26);
            for(auto c : s){
                feq[c-'a']++;
            }
            for(int i = 0; i<26; i++){
                universal[i] = max(universal[i], feq[i]);
            }
        }

        vector<string>ans;
        for(auto &s : words1){
            vector<int>feq(26);
            for(auto c : s){
                feq[c-'a']++;
            }

            bool isSuper = true;
            for(int i = 0; i<26; i++){
                if(feq[i]<universal[i]){
                    isSuper = false; break;
                }
            }
            if(isSuper) ans.push_back(s);
        }
        return ans;
    }
};