class Solution {
public:
int size(ListNode* head){
    int count=0;
        ListNode* temp=head;
        while(temp!= NULL){
            temp=temp->next;
            count++;
           
        }
        return count;
        

}
    ListNode* deleteMiddle(ListNode* head) {
        
   
        if(!head || !head->next){
            return NULL;
        }
        int n=size(head);
        int middle=n/2;

        ListNode* temp=head;
        for(int i=0;i<middle-1; i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};
