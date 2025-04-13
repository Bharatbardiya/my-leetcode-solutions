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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>>mp;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        vector<vector<int>>ans;

        while(q.size()>0){
            int x = q.size();
            map<int, vector<int>>mp2;
            for(int i = 0; i<x; i++){
                auto pr = q.front(); q.pop();
                TreeNode* curr = pr.first;
                int level = pr.second;
                mp2[level].push_back(curr->val);

                if(curr->left){
                    q.push({curr->left, level-1});
                }
                if(curr->right){
                    q.push({curr->right, level+1});
                }
            }
            for(auto pr : mp2){
                int key = pr.first;
                sort(pr.second.begin(), pr.second.end());
                for(auto x : pr.second){
                    mp[key].push_back(x);
                }
            }
        }

        for(auto pr : mp){
            // sort(pr.second.begin(), pr.second.end());
            ans.push_back(pr.second);
        }
        return ans;
    }
};