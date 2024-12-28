
class Trie{
    public:
    vector<Trie*>arr;
    bool isEnd;

    Trie(){
        arr.resize(26, NULL);
        isEnd = false;
    }

    void insert(string &s, Trie*root){
        for(auto c : s){
            int ind = c-'a';
            if(root->arr[ind]==NULL){
                root->arr[ind] = new Trie();
            }
            root = root->arr[ind];
        }
        root->isEnd = true;
    }
};

class MagicDictionary {
public:
    Trie *root = new Trie();
    MagicDictionary() {
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto s : dictionary){
            root->insert(s, root);
        }
    }
    
    bool search(string searchWord) {
        // cout<<endl;
        return _search(searchWord, root, 0, true);
    }

    bool _search(string &s, Trie *curr, int i, bool chance){

        if(i==s.length()){
            // cout<<i<<","<<curr->isEnd<<","<<chance<<endl;
            if(chance) return false;
            return curr->isEnd;
        }
        
        int ind = s[i]-'a';
        bool temp = false;
        for(int j = 0; j<26; j++){
            if(curr->arr[j] != NULL){
                if(j==ind) temp = _search(s, curr->arr[j], i+1, chance);
                else if(chance) temp = _search(s, curr->arr[j], i+1, false);
                if(temp) return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */