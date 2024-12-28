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
    bool fun(TreeNode* root, TreeNode*curr){
        if(root==curr) return true;
        else if(root==NULL or curr==NULL) return false;
        if(root->val!=curr->val) return false;
        return fun(root->left, curr->left) and fun(root->right, curr->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==subRoot) return true;
        else if(root==NULL or subRoot==NULL) return false;
        return fun(root, subRoot) or isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot); 
    }
};