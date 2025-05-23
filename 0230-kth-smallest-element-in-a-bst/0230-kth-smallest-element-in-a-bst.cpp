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
    int dfs(TreeNode*root, int &k){
        if(root==NULL) return -1;
        int val1=dfs(root->left,k);
        if(val1!=-1) return val1;

        k--;
        if(k==0) return root->val;
        return dfs(root->right,k);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        return dfs(root, k);
    }
};