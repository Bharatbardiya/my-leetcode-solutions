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
    int maxLevelSum(TreeNode* root) {
        int ans = -1e9, level = 0, curr_level = 1;
        queue<TreeNode*>q;
        q.push(root);

        while(q.size()>0){
            int size = q.size();
            int temp = 0;
            for(int i = 0; i<size; i++){
                TreeNode*curr = q.front(); q.pop();
                temp+=curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(ans<temp){
                ans = temp;
                level = curr_level;
            }
            curr_level++;
        }
        return level;
    }
};