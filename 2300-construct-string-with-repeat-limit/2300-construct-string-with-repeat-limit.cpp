class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        vector<int>feq(26);

        for(auto c : s){
            feq[c-'a']++;
        }
        priority_queue<pair<char,int>>pq;
        for(int i = 0; i<26; i++){
            if(feq[i]>0)
                pq.push({'a'+i, feq[i]});
        }
        string ans = "";
        while(pq.size()>0){
            auto pr = pq.top();
            pq.pop();
            char c = pr.first;
            int fq = pr.second;
            
            for(int i = 0; i<min(fq,limit); i++) ans.push_back(c);
            if(fq>limit){
                if(pq.empty()) break;
                fq = fq-limit;
                auto pr2 = pq.top();
                pq.pop();
                char c2 = pr2.first;
                int fq2 = pr2.second;
                ans.push_back(c2);
                fq2--;

                pq.push({c,fq});
                if(fq2>0) pq.push({c2,fq2});
            }
        }
        return ans;
    }
};