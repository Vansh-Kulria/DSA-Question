/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //no cycle -> fast == nULL
        //yes, cycle -> slow == fast
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL) {
            fast = fast -> next;
            if(fast != NULL) {
                fast = fast -> next;
                slow = slow -> next;
                //check whether they are meeting
                if(slow == fast) {
                    return true;
                }
            }
        }
        //loop se bahar tabhi aaega, jab fast NULL hoga 
        return false;
    }
};

