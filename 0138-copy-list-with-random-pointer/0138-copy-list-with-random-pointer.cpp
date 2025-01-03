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
        
        Node*curr = head;

        while(curr!=NULL){
            Node*temp = new Node(curr->val);
            Node*next = curr->next;
            curr->next = temp;
            temp->next = next;
            curr = next;
        }
        curr = head;
        while(curr!=NULL){
            Node*newNode = curr->next;
            if(curr->random)
                newNode->random = curr->random->next;
            curr = newNode->next;
        }
        curr = head;
        Node*head2 = new Node(0);
        Node*curr2 = head2;

        while(curr!=NULL){
            Node*next = curr->next->next;
            curr2->next = curr->next;
            curr->next = next;
            
            curr2 = curr2->next;
            curr = curr->next;
        }
        // curr = head;
        // while(curr!=NULL){
        //     cout<<curr->val<<": ";
        //     if(curr->random) cout<<curr->random->val<<endl;
        //     else cout<<"null "<<endl;
        //     curr =curr->next;
        // }
        return head2->next;
    }
};