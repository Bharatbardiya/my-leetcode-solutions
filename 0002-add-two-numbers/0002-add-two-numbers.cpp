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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int rem = 0;
        ListNode*first=l1, *second = l2;
        ListNode*head = new ListNode(0);
        ListNode*curr = head;
        while(first!=NULL or second!=NULL){
            int val1 = 0, val2 = 0;
            if(first!=NULL){
                val1 = first->val;
                first = first->next;
            }
            if(second!=NULL){
                val2 = second->val;
                second = second->next;
            }
            int sum = (val1+val2+rem);
            if(sum>=10){
                sum = sum%10; rem = 1;
            }
            else rem = 0;
            curr->next = new ListNode(sum);
            curr = curr->next;
        }
        
        if(rem==1) curr->next = new ListNode(1);
        return head->next;
    }
};