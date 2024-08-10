Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.






  class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            s+=s[i];
            string sub=s.substr(i+1,n+1);
            if(sub==goal){
                return true;
            }
            
        }
        return false;

        
    }
};
