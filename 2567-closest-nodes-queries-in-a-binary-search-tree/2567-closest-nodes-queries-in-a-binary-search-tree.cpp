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
    int lower_value(TreeNode* root, int val){
        if(root==NULL) return -1;
        if(root->val==val) return val;
        
        if(root->val>val) return lower_value(root->left, val);
        
        int v1 = root->val;
        int v2 = lower_value(root->right, val);
        if(v2!=-1) return v2;
        return v1;
    }

    int upper_value(TreeNode* root, int val){
        if(root==NULL) return -1;
        if(root->val==val) return val;
        
        if(root->val<val) return upper_value(root->right, val);
        
        int v1 = root->val;
        int v2 = upper_value(root->left, val);
        if(v2!=-1) return v2;
        return v1;
    }

    void dfs(TreeNode* root, vector<int>&arr){
        if(root==NULL) return;
        dfs(root->left, arr);
        arr.push_back(root->val);
        dfs(root->right, arr);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int>arr;
        dfs(root, arr);
        vector<vector<int>>ans;
        // for(auto x : arr) cout<<x<<",";
        // cout<<endl;
        for(auto q : queries){
            vector<int>t = {-1,-1};
            auto it = lower_bound(arr.begin(), arr.end(), q);
            if(it!=arr.end()) t[1] = *it;
            if(it!=arr.end() and *it==q) t[0] = *it;
            else if(it!=arr.begin()){
                it--;
                t[0] = *it;
            }
            ans.push_back(t);
        }
        return ans;
    }
};