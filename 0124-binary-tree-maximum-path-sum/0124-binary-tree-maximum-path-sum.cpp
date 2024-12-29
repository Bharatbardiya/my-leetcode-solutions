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
    int _maxPathSum(TreeNode* root, int &ans){
        if(root==NULL) return 0;

        int val = root->val;
        int left = _maxPathSum(root->left, ans);
        int right = _maxPathSum(root->right, ans);
        if(left>0) val+=left;
        if(right>0) val+=right;
        ans = max(ans, val);
        return root->val+max(0,max(left,right));
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        _maxPathSum(root, ans);
        return ans;
    }
};