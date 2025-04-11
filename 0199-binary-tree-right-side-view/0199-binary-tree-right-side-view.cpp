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
    void dfs(TreeNode* root, map<int,int>&mp, int hlevel){
        if(root==NULL) return;
        mp[hlevel] = root->val;
        dfs(root->left, mp, hlevel+1);
        dfs(root->right, mp, hlevel+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        map<int,int>mp;
        vector<int>ans;
        dfs(root, mp, 0);
        for(auto pr : mp){
            ans.push_back(pr.second);
        }
        return ans;
    }
};