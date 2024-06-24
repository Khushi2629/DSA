Given the head of a linked list head, in which each node contains an integer value.

Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.

Return the linked list after insertion.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.



 int gcd(int first,int second)
 {
    while(second!=0)
    {
        int temp=second;
        second=first % second;
        first=temp;
    }
    return first;
 }

 void insert(ListNode* prev,ListNode* forward,int data)
 {
    ListNode* newNode=new ListNode(data);
    prev->next=newNode;
    newNode->next=forward;
 }
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head-> next == NULL)
        {
            return head;
        }

        ListNode* temp = head-> next;
        ListNode* prev = head;

        while(temp != NULL)
        {
            int first = prev-> val;
            int second = temp-> val;
            int data = gcd(first,second);
            insert(prev,temp,data);
            prev = temp;
            temp = temp-> next;
        }
        return head;

        
    }
}; 
