You are given the head of a linked list.

Remove every node which has a node with a greater value anywhere to the right side of it.

Return the head of the modified linked list.




  class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        deque<ListNode* >q;

        while (head)
        {
            while (!q.empty() && q.back()->val < head->val)
            {
                q.pop_back();
            }

            q.push_back(head);
            head = head->next;
        }

        if (!q.empty())
        {
            head = q.front();
        }

        ListNode* curr = head;
        while (!q.empty()) 
        {
            curr->next = q.front();
            q.pop_front();

            curr = curr->next;
        }
        curr->next = NULL;
        
        return head;
    }
};
