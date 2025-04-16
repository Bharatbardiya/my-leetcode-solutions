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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*>st;
        st.push(root);
        bool isleft = true;
        vector<vector<int>>ans;
        
        if(root==NULL) return ans;

        while(st.size()>0){
            int size = st.size();
            vector<int>arr;
            stack<TreeNode*>st2;
            for(int i = 0; i<size; i++){
                TreeNode* curr = st.top(); st.pop();
                arr.push_back(curr->val);
                if(isleft){
                    if(curr->left) st2.push(curr->left);
                    if(curr->right) st2.push(curr->right);
                }
                else{
                    if(curr->right) st2.push(curr->right);
                    if(curr->left) st2.push(curr->left);
                }
            }
            st = st2;
            ans.push_back(arr);
            isleft = !isleft;
        }
        return ans;
    }
};