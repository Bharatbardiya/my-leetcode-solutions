/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // burte force
        map<Node*, Node*>mp;

        Node *head2 = new Node(0);
        Node *temp = head2, *curr = head; 

        while(curr!=NULL){
            int val = curr->val;
            Node*newNode = new Node(val);
            temp->next = newNode;
            mp[curr] = newNode;

            temp = temp->next;
            curr = curr->next;
        }
        head2 = head2->next;
        temp = head2;
        curr = head;

        while(curr!=NULL){
            Node*random = curr->random;
            Node*newRandom = mp[curr->random];
            temp->random = newRandom;

            temp = temp->next;
            curr = curr->next;
        }
        return head2;
    }
};