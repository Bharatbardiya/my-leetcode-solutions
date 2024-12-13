/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
		// Input: root = [1 [3[5 6] 2 4]]
		// " 1 [ 3 [ 5 [] 6 [] ] 4 [] 2 [] 
    void dfs(Node* root, string &ans){
	    ans.push_back(' ');
        // cout<<ans<<endl;
	    ans+=to_string(root->val);
	    ans.push_back(' ');
	    ans.push_back('[');
	    for(auto child : root->children){
		    dfs(child, ans);
	    }
	    ans.push_back(']');
	    ans.push_back(' ');
    }
    
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string ans = "";
        if(root==NULL) return ans;
        dfs(root, ans);
        return ans;
    }
		vector<string>splitStr(string &s){
			int i = 0;
			vector<string>ans;
			string curr = "";
			
			while(i<s.length()){
				if(s[i]==' '){
					if(curr!="") ans.push_back(curr);
					curr = "";
				}
				else curr.push_back(s[i]);
				i++;
			}
			return ans;
		}
    Node* _deserialize(vector<string>&data, int &ind){
        Node* root = new Node(stoi(data[ind]));
        // cout<<data[ind]<<",";
        ind++;
        if(data[ind]=="[]"){
            ind++;
            return root;
        }
        ind++;
        while(ind<data.size() and data[ind]!="]"){
            Node* child = _deserialize(data, ind);
            root->children.push_back(child);
        }
        ind++;
        return root;
    }
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if(data=="") return NULL;
        int ind = 0;
        vector<string>data_array = splitStr(data);
        // for(auto s : data_array) cout<<s<<"-";
        // cout<<endl;
        // " 1 [ 3 [ 5 [] 6 [] ] 4 [] 2 [] "
        // {'1', '[', '3', '[', '5', '[]', 6, '[]', ']', '4', '[]', '2', '[]'}
        return _deserialize(data_array, ind);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));