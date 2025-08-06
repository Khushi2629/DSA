Given the head of a singly linked list, return true if it is a palindrome or false otherwise.



  class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> ans;  
        while(head !=NULL){
            ans.push_back(head->val);
            head=head->next;

        }
        int l=0, n=ans.size()-1;
        while(l< n && ans[l] == ans[n]){
            l++;
            n--;
        }
        return l>=n;
        
        
    }
};
