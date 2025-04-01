Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).







class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        int j = 0;
        
        // An empty string s is a subsequence of any string t.
        if(n == 0)
            return true;
        
        // Iterate over t (the longer string)
        for(int i = 0; i < m && j < n; i++){
            if(t[i] == s[j]){
                j++;
            }
        }
        
        // If we've matched all characters in s, then s is a subsequence of t.
        return j == n;
    }
};
