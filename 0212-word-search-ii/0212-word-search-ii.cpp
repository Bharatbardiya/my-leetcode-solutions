class Trie{
    public:
    vector<Trie*>child;
    bool isEnd;

    Trie(){
        isEnd = false;
        child.resize(26, NULL);
    }

    void insert(string s){
        Trie *root = this;
        for(int i = 0; i<s.length(); i++){
            int ind = s[i]-'a';
            if(root->child[ind]==NULL) root->child[ind] = new Trie();
            root = root->child[ind];
        }
        root->isEnd = true;
    }
    bool search(string &s, int len){
        Trie*root = this;
        for(int i = 0; i<len; i++){
            int ind = s[i]-'a';
            if(root->child[ind]==NULL) return false;
            root = root->child[ind];
        }
        return (root->isEnd);
    }
};


class Solution {
public:
    unordered_set<string>ans;
    void fun(vector<vector<char>>&board, string&curr, int i, int j, vector<vector<bool>>&vis, int maxl, unordered_set<string>&st){
        if(curr.length()>maxl){
            return;
        }
        int n = board.size(), m = board[0].size();
        if(i>=n or i<0 or j>=m or j<0) return;
        
        if(vis[i][j]) return;
        curr.push_back(board[i][j]);
        vis[i][j] = true;
        
        if(st.find(curr) != st.end()){
            ans.insert(curr);
        }

        fun(board, curr, i+1, j, vis, maxl, st);
        fun(board, curr, i-1, j, vis, maxl, st);
        fun(board, curr, i, j+1, vis, maxl, st);
        fun(board, curr, i, j-1, vis, maxl, st);

        vis[i][j] = false;
        curr.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie*root = new Trie();
        int n = board.size(), m = board[0].size();
        int maxl=0;
        unordered_set<string>st;
        for(auto s : words){
            st.insert(s);
            maxl = max(maxl, (int)s.length()); 
        }
        vector<vector<bool>>vis(n, vector<bool>(m,false));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                string curr = "";
                fun(board, curr, i,j, vis, maxl, st);
            }
        }
        vector<string>Answer;
        for(auto s : ans){
            // cout<<s<<"|";
            Answer.push_back(s);
        }
        // for(auto s : st) cout<<s<<"|";
        return Answer;
    }
};