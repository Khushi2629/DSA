You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.

For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

Return the head of the modified linked list.





  class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head->next;
        ListNode* anshead = new ListNode(-1);
        ListNode* anstail = anshead;

        int sum=0;
        while(temp != NULL){
            if(temp->val ==0){
                ListNode* newNode = new ListNode(sum);
                anstail->next = newNode;
                anstail= newNode;
                sum=0;
            }
            else{
                sum+=temp->val;

            }
            temp=temp->next;
        }
        return anshead->next;
        
    }
};
