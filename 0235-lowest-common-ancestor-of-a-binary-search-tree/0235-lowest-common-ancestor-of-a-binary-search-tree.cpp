/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val>q->val) return lowestCommonAncestor(root, q, p);
        if(root==NULL) return NULL;
        if(p==root or q==root) return root;
        int val = root->val, pval = p->val, qval = q->val;
        
        if(val<pval and val<qval) return lowestCommonAncestor(root->right, p, q);
        else if(val>pval and val>qval) return lowestCommonAncestor(root->left, p, q);
        return root;
        
    }
};