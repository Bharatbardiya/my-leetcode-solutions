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
    TreeNode* buildTree(vector<int>&preorder, vector<int>&inorder, int &i, int l, int r){
        if(l>r) return NULL;

        int k = -1;
        for(int j = l; j<=r; j++){
            if(inorder[j]==preorder[i]){
                k = j; break;
            }
        }
        TreeNode* curr = new TreeNode(preorder[i]);
        i++;
        curr->left = buildTree(preorder, inorder, i, l, k-1);
        curr->right = buildTree(preorder, inorder, i, k+1, r);
        return curr;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder = preorder;
        sort(inorder.begin(), inorder.end());
        // for(auto x : preorder) cout<<x<<",";
        // cout<<endl;
        // for(auto x : inorder) cout<<x<<",";

        int i = 0;
        return buildTree(preorder, inorder, i, 0, preorder.size()-1);
    }
};