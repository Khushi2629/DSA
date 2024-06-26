You are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their place.




class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* point1=list1;
        int count=1;
        while(count!=a)
        {
            point1=point1->next;
            count++;
        }
        ListNode *point2=point1->next;
        while(count!=b+1)
        {
            point2=point2->next;
            count++;
        }
        point1->next=list2;
        ListNode *temp=list2;
        while(temp->next !=NULL)
        temp=temp->next;
        temp->next=point2;
        return list1;
        
    }
};
