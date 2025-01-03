/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int listLength(ListNode*head){
        int n = 0;
        while(head!=NULL){
            head = head->next;
            n++;
        }
        return n;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = listLength(head);
        if(len==1) return NULL;
        if(n==len) return head->next;

        int pos = len-n;
        ListNode*curr = head;
        while(curr!=NULL and pos>1){
            curr = curr->next;
            pos--;
        }
        
        ListNode *next = curr->next->next;
        delete curr->next;
        curr->next = next;
        return head;

    }
};