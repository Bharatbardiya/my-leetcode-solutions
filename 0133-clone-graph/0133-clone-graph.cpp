/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>&mp){
        if(node==NULL) return NULL;
        Node* curr = NULL;
        if(mp.find(node) != mp.end()){
            curr = mp[node];
        }
        else curr = new Node(node->val);
        mp[node] = curr;

        for(auto nig : node->neighbors){
            if(mp.find(nig)!=mp.end()){
                curr->neighbors.push_back(mp[nig]);
            }
            else curr->neighbors.push_back(dfs(nig, mp));
        }
        return curr;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>mp;
        return dfs(node, mp);
    }
};