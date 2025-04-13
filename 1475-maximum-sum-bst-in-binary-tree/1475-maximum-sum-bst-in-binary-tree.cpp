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
    vector<int> helper(TreeNode*root, int &ans){
        if(root==NULL) return {0,0,0,1};

        vector<int>v1 = helper(root->left, ans), v2 = helper(root->right, ans);
        if(v1[3]==0 or v2[3]==0) return {0,0,0,0};
        int t = root->val;
        if((root->left!=NULL and t<=v1[2]) or (root->right!=NULL and t>=v2[1])) return {0,0,0,0};
        
        int temp = t + v1[0] + v2[0];
        // cout<<temp<<","<<root->val<<"\n";
        ans = max(ans, temp);
        int mini = v1[1], maxi = v2[2];
        if(root->left==NULL) mini = t;
        if(root->right==NULL) maxi = t;
        return {temp, mini, maxi, 1};
    }

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        vector<int> data = helper(root, ans);
        return ans;
    }
};