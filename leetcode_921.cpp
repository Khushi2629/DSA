A parentheses string is valid if and only if:

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.






  class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push('(');
            else{
                if(st.empty()) cnt++;
                else{
                    if(st.top()!='(') cnt++;
                    else st.pop();
                }
            }
        }
        cnt += st.size();
        return cnt;
    }
};
