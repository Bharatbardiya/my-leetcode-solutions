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
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()==false){
            
            int x = q.size();
            level++;
            for(int i = 0; i<x; i++){
                
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                
            }
            if(level%2==1){
                vector<TreeNode*>v;
                while(!q.empty()){
                    v.push_back(q.front());
                    q.pop();
                }
                int i = 0, j = v.size()-1;
                while(i<j){
                    int temp = v[i]->val;
                    v[i]->val = v[j]->val;
                    v[j]->val = temp;
                    i++; j--;
                }
                for(auto k : v) q.push(k);
            }
        }
        return root;
    }
};