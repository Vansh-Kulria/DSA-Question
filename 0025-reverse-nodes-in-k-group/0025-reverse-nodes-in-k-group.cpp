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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // step 1 check group present of len k 
        int count = 0;
        ListNode * temp = head;

        while(temp != NULL && count < k ){
            temp = temp -> next;
            count++;
        }

        // if group exist
        if(count == k){
            // reverse 1 group and baali recursion dekega
            ListNode* prev = NULL; 
            ListNode* curr = head; 
            ListNode* forward;
            // i need to reverse k node 
            int  i = 0;
            while(i < k){
                forward = curr -> next;
                curr->next = prev;
                prev = curr;
                curr = forward;
                i++;
            }

            // 1 group reversed
            // baaki recursion
            ListNode* recursionHead = reverseKGroup(forward, k);
            // dono LL ko join
            head -> next = recursionHead;
            // return starting node of modified LL
            return prev;
        }
        else{
            return head;
        }
    }
};