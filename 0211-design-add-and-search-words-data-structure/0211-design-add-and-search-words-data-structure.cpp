class Trie{
public:
    vector<Trie*>child;
    bool isEnd;

    Trie(){
        child.resize(26, NULL);
        isEnd = false;
    }

    void insert(string s){
        Trie*root = this;
        for(int i = 0; i<s.length(); i++){
            int ind = s[i]-'a';
            if(root->child[ind]==NULL) root->child[ind] = new Trie();
            root = root->child[ind];
        }
        root->isEnd = true;
    }

    bool search(string s, int i, Trie*root){
        if(i==s.length()){
            return root->isEnd;
        }
        if(s[i]!='.'){
            int ind = s[i]-'a';
            if(root->child[ind]==NULL) return false;
            return search(s, i+1, root->child[ind]);
        }
        for(int itr = 0; itr<26; itr++){
            if(root->child[itr]!=NULL){
                if(search(s, i+1, root->child[itr])) return true;
            }
        }
        return false;
    }
};

class WordDictionary {
public:
    Trie*root;
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        root->insert(word);
    }
    
    bool search(string word) {
        return root->search(word, 0, root);
    }
};
// bad, dad, 
// .ad
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */