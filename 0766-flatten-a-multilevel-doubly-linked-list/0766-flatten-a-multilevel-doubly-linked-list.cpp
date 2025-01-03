/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* dfs(Node* head, Node* &prev){
        if(head==NULL) return NULL;
        // cout<<head->val<<",";
        // if(prev==NULL){
        //     cout<<"NULL),";
        // }
        // else cout<<prev->val<<"),";
        Node* next = head->next;
        head->prev = prev;
        prev = head;
        if(head->child){
            head->next = dfs(head->child, prev);
            head->child = NULL;
            Node*curr = head;
            while(curr->next!=NULL) curr = curr->next;
            curr->next = dfs(next, prev);
        }
        else head->next = dfs(head->next, prev);
        return head;
    }
    Node* flatten(Node* head) {
        Node* prev = NULL;
        head = dfs(head, prev);
        // Node*curr = head;
        // while(curr!=NULL){
        //     cout<<curr->val<<",";
        //     if(curr->child) cout<<"(child "<<curr->child->val<<"),";
        //     curr = curr->next;
        // }
        return head;
    }
};