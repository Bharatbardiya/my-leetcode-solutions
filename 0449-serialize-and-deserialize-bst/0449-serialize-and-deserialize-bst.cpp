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
    void dfs(TreeNode* root, string& ans) {
        if (root == NULL) {
            ans.push_back('#');
            ans.push_back(' ');
            return;
        }
        ans += to_string(root->val);
        ans.push_back(' ');
        dfs(root->left, ans);
        dfs(root->right, ans);
    }
    // Encodes a tree to a single string.
    // [2,1,3] -> 1 2 # # 3 # #
    string serialize(TreeNode* root) {
        string ans = "";
        dfs(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    vector<string> splitBySpace(string& s) {
        string curr = "";
        vector<string> ans;
        int index = 0;
        while (s.length() > index) {
            if (s[index] == ' ') {
                ans.push_back(curr);
                curr = "";
            } else
                curr.push_back(s[index]);
            index++;
        }
        // ans.push_back(curr);
        return ans;
    }

    TreeNode* _deserialize(vector<string>& data, int &ind) {
        if (data[ind] == "#") {
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(data[ind]));
        root->left = _deserialize(data, ++ind);
        root->right = _deserialize(data, ++ind);
        return root;
    }

    TreeNode* deserialize(string data) {
        vector<string> serialize_data = splitBySpace(data);
        // ['1','2','#','#','3','#','#']
        int ind = 0;
        return _deserialize(serialize_data, ind);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;