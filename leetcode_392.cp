Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).







class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=t.size();
        int k=s.size();
        int j=0;
        if(k==0)
        return true;

        for(int i=0;i<n;i++){
            if(s[j]==t[i]){
                j++;
            }
            
        }
        if(j==k){
            return true;

        }
        return false;
        
    }
};
