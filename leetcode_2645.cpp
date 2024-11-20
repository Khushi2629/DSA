Given a string word to which you can insert letters "a", "b" or "c" anywhere and any number of times, return the minimum number of letters that must be inserted so that word becomes valid.

A string is called valid if it can be formed by concatenating the string "abc" several times.







  class Solution {
public:
    int addMinimum(string word) {
        string s="abc";
        int ans=0;
        int i=0,j=0;
        int n=word.length();
        while(i<n){
            if(word[i]==s[j++]) i++;
            else{
                ans++;

            }
          
            j%=3;
        }
        if(word[n-1]=='a') return ans+2;
        if(word[n-1]=='b') return ans+1;
        return ans;
        
        
    }
};
