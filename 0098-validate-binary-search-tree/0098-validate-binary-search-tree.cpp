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
    vector<int>fun(TreeNode* root){
        
        if(root->left==root->right) return {true, root->val, root->val};

        int val = root->val, mini = root->val, maxi=root->val;
        if(root->left!=NULL){
            vector<int>vl = fun(root->left);
            if(vl[0]==0) return {0,0,0};
            if(val<=vl[2]) return {0,0,0};
            mini = vl[1];
        }

        if(root->right!=NULL){
            vector<int>vr = fun(root->right);
            if(vr[0]==0) return {0,0,0};
            if(val>=vr[1]) return {0,0,0};
            maxi = vr[2];
        }

        return {true, mini, maxi};
    }

    bool isValidBST(TreeNode* root) {
        vector<int>v = fun(root);
        return v[0];
    }
};