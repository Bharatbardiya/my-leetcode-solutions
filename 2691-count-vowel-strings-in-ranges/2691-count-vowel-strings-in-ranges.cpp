class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>pre(n+1,0);
        set<char>st = {'a','e','i','o','u'};

        for(int i = 0; i<n; i++){
            char lc = words[i][0], lr = words[i].back();
            if(st.count(lc)>0 and st.count(lr)>0){
                pre[i+1] = pre[i]+1;
            } else pre[i+1] = pre[i];
        }

        vector<int>ans;
        for(auto query: queries){
            ans.push_back(pre[query[1]+1]-pre[query[0]]);
        }
        return ans;
    }
};