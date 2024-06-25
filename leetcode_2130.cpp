In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.






  class Solution {
public:
    int pairSum(ListNode* head) {
        if(head==NULL) return 0;
        if(head->next->next==NULL) return head->val+ head->next->val;

        stack<int>st;
        stack<int>st1;
        stack<int>st2;

        while(head){
            st.push(head->val);
            st1.push(head->val);
            head=head->next;
        }
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int x=0;
        while(!st.empty() && !st2.empty()){
            x=max(x,st.top()+st2.top());
            st.pop();
            st2.pop();
        }
        return x;
        
    }
};
