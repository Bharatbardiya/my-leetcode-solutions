class Node{
    public:
    vector<Node*>child;
    bool isEnd;
        Node(){
            this->isEnd = false;
            this->child.resize(26, NULL);
        }
};

class Trie {
public:
    Node*root;
    Trie() {
        root = new Node();
    }
    // "a"
    void insert(string word) {
        Node*curr = root;// root -> 26(NULL)
        for(char c : word){
            int ind = c-'a';
            if(curr->child[ind]==NULL){
                // true 
                // 
                curr->child[ind] = new Node();
            }
            curr = curr->child[ind];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        Node*curr = root;
        for(char c : word){
            int ind = c-'a';
            if(curr->child[ind]==NULL){
                return false;
            }
            curr = curr->child[ind];
        }
        return (curr->isEnd);
    }
    
    bool startsWith(string prefix) {
        Node*curr = root;
        for(char c : prefix){
            int ind = c-'a';
            if(curr->child[ind]==NULL){
                return false;
            }
            curr = curr->child[ind];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */