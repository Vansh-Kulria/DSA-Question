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
    Node* solve(Node* head, Node* &tail){

        Node* temp = head;

        while(temp){

            // Attach current node
            tail->next = temp;
            temp->prev = tail;
            tail = temp;

            Node* next = temp->next;

            // Flatten child if it exists
            if(temp->child){

                solve(temp->child, tail);

                temp->child = NULL;
            }

            temp = next;
        }

        return tail;
    }

    Node* flatten(Node* head) {

        if(head == NULL)
            return NULL;

        Node dummy(0);
        Node* tail = &dummy;

        solve(head, tail);

        dummy.next->prev = NULL;

        return dummy.next;
    }
    };