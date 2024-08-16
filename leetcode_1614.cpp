Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.



class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int ans=0; int n=0;
        for(int i=0;i<s.length();i++){
            char c =s[i];
            if(c=='('){
                st.push(c);
                ans++;
            }
            char top=st.top();
            if(c==')' && top=='('){
                st.pop();
                n=max(ans,n);
                ans--;
            }
        }
        return n;
        
    }
};
