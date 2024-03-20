Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

1.Open brackets must be closed by the same type of brackets.
2.Open brackets must be closed in the correct order.
3.Every close bracket has a corresponding open bracket of the same type.



  class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if(ch=='('|| ch=='{'|| ch=='[')
            {
                st.push(ch);
            }
            else{
                if(!st.empty())
                {
                    char top = st.top();
                    if((ch==')'&& top=='(') ||
                        (ch=='}' && top=='{') ||
                        (ch==']' && top=='['))
                        {
                            st.pop();
                        }
                        else
                        {
                            return false;
                        }
                }
                else
                {
                    return false;
                }
            }
        }
        if(st.empty())
        {
            return true;
        }
        return false;

        
    }
};
