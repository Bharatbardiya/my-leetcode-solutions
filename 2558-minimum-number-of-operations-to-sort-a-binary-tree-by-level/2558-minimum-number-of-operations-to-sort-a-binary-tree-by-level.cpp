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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(q.size()>0){
            int x = q.size();
            vector<int>level;
            for(int i = 0; i<x; i++){
                TreeNode *cur = q.front();
                q.pop();
                level.push_back(cur->val);
                if(cur->left!=NULL) q.push(cur->left);
                if(cur->right!=NULL) q.push(cur->right);
            }
            vector<int>temp = level;
            sort(temp.begin(), temp.end());
            map<int,int>mp;
            for(int i = 0; i<temp.size(); i++) mp[temp[i]] = i;

            for(int i = 0; i<level.size(); i++){
                level[i] = mp[level[i]];
            }
            
            for(int i = 0; i<level.size(); i++){
                int t = 0;
                while(level[i]!=i){
                    swap(level[i], level[level[i]]);
                    t++;
                }
                // cout<<t<<"),";
                ans += t;
            }
            // cout<<endl;
        }
        return ans;
    }
};