class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>vis;
        set<string>wordlist;
        for(auto s : wordList){
            wordlist.insert(s);
        }
        if(wordlist.find(endWord)==wordlist.end()) return 0;
        queue<string>q;
        q.push(beginWord);
        vis.insert(beginWord);
        int dis = 0;
        while(q.size()>0){
            int x = q.size();
            dis++;
            for(int l = 0; l<x; l++){
                string cur = q.front();
                if(cur==endWord) return dis;
                q.pop();

                for(int i = 0; i<cur.length(); i++){
                    char temp = cur[i];
                    for(int j = 0; j<26; j++){
                        char c = 'a'+j;
                        if(c!=temp){
                            cur[i] = c;
                        }
                        if(wordlist.find(cur)!=wordlist.end() and vis.find(cur)==vis.end()){
                            q.push(cur);
                            vis.insert(cur);
                        }
                    }
                    cur[i] = temp;
                }
            }
        }
        return 0;
    }
};