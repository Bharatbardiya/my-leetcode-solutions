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
    TreeNode* makingTree(map<int,int>&indices, vector<int>&preorder, int &i, int l, int r){
        if(l>r) return NULL;
        int val = preorder[i];
        TreeNode *root = new TreeNode(val);
        i++;
        root->left = makingTree(indices, preorder, i, l, indices[val]-1);
        root->right = makingTree(indices, preorder, i, indices[val]+1, r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>indices;
        int n = preorder.size();
        for(int i = 0; i<n; i++){
            indices[inorder[i]] = i;
        }
        int ind = 0;
        return makingTree(indices, preorder, ind, 0, n-1);
    }
};