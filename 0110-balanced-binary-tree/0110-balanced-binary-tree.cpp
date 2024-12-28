/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,bool> fun(TreeNode* root){
        if(root==NULL) return {0,true};

        pair<int,bool> pr1 = fun(root->left), pr2 = fun(root->right);
        int height = 1+max(pr1.first,pr2.first);
        if(abs(pr1.first-pr2.first)>=2 or !pr1.second or !pr2.second) return {height, false};
        return {height, true};

    }
    bool isBalanced(TreeNode* root) {
        return fun(root).second;
    }
};