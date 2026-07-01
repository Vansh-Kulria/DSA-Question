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
    ListNode* deleteDuplicates(ListNode* head) {

        //empty linked list 
        if(head == NULL) {
            return head;
        }
        //single node linked list 
        if(head->next == NULL) {
            return head;
        }

        //main logic 
        ListNode* prev = head;
        ListNode* curr = head->next;

        while(curr != NULL) {
            if(curr->val != prev->val) {
                curr = curr->next;
                prev = prev->next;
            }
            else {
                //if val are equal 
                prev->next = curr->next;
                curr->next = NULL;
                delete curr;
                //reinitialise curr
                curr = prev->next;
            }
        }
        return head;
    }
};