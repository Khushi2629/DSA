


Given the head of a singly linked list, reverse the list, and return the reversed list.



  class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr=head;
        ListNode* next=nullptr;

        while(curr!=nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
        
    }
};
