/*  Given a linked list, delete N nodes after skipping M nodes of a linked list until the last of the linked list. */

class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        Node* dummy = new Node(-1);
        Node* prev = dummy;
        prev->next = head;
        while (head != NULL) {         
            for (int i = 0; (i < M) && (head != NULL); ++ i) {
                prev = head;
                head = head->next;
            }
            for (int i = 0; (i < N) && (head != NULL); ++ i) {
                head = head->next;
            }            
            prev->next = head;
        }
        cout<<dummy->next->data;
    }
};
