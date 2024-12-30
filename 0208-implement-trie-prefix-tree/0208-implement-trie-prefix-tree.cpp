class Trie{
	public:

	bool isEnd;
	vector<Trie*>child;

	Trie(){
		isEnd = false;
		child.resize(26,NULL);
	}

	void insert(string s){
		Trie*root = this;
		for(int i = 0; i<s.length(); i++){
			int ind = s[i]-'a';
			if(root->child[ind]==NULL){
				root->child[ind] = new Trie();
			}
			root = root->child[ind];
		}
		root->isEnd = true;
	}

	bool search(string s){
		Trie*root = this;
		for(int i = 0; i<s.length(); i++){
			int ind = s[i]-'a';
			if(root->child[ind]==NULL) return false;
			root = root->child[ind];
		}
		return (root->isEnd==true);
	}

	bool startsWith(string s){
		Trie*root = this;
		for(int i = 0; i<s.length(); i++){
			int ind = s[i]-'a';
			if(root->child[ind]==NULL) return false;
			root = root->child[ind];
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