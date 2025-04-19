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
    void allPath(TreeNode* root, int t, vector<int>&arr, vector<vector<int>>&ans){
        if(root==NULL) return;
        arr.push_back(root->val);
        if(root->left==root->right and root->val==t)
            ans.push_back(arr);

        allPath(root->left, t-root->val, arr, ans);
        allPath(root->right, t-root->val, arr, ans);
        arr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>arr;
        allPath(root, targetSum, arr, ans);
        return ans;
    }
};