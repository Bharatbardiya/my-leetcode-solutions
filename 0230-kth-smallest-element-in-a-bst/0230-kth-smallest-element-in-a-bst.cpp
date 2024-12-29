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
    int fun(TreeNode *root, int &k){
        if(root==NULL) return -1;
        int left = fun(root->left, k);
        if(left!=-1) return left;
        if(k==1) return root->val;
        k--;
        return fun(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        return fun(root, k);
    }
};