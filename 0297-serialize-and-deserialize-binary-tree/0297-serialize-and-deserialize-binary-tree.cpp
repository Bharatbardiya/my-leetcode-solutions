/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(root==NULL) return "null";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(cur==NULL){
                ans+="null,";
            } else{
                ans+=(to_string(cur->val)+",");
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        // cout<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="null,") return NULL;
        vector<string>nodes;
        string curr = "";
        for(auto c : data){
            if(c==','){
                nodes.push_back(curr); curr = "";
            }
            else curr.push_back(c);
        }
        // for(auto x : nodes) cout<<x<<",";
        // cout<<endl;
        TreeNode* root = NULL;
        queue<TreeNode*>q;
        int isLeft = true;
        for(auto val : nodes){
            
            TreeNode*node;
            if(val=="null") node = NULL;
            else node = new TreeNode(stoi(val));
            if(root==NULL) root = node;

            if(q.size()==0 and node!=NULL){
                q.push(node);
            }
            else{
                TreeNode*pr = q.front();
                if(isLeft){
                    pr->left = node; isLeft = false;
                } else {
                    pr->right = node; isLeft = true;
                    q.pop();
                }
                if(node!=NULL) q.push(node);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));