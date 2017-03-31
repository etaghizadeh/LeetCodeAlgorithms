/*   Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 
 The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 
 */

class Solution {
public:
    bool isValid(string s) {
        for(int i=0; i<s.length(); i++)
        {
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch=='[')
                stk.push(ch);
            else
            {
                switch (ch)
                {
                    case ')':
                        if(stk.empty() || stk.top()!= '(')
                            return false;
                        stk.pop();
                        break;
                    case ']':
                        if(stk.empty() || stk.top()!= '[')
                            return false;
                        stk.pop();
                        break;
                    case '}':
                        if(stk.empty() || stk.top()!= '{')
                            return false;
                        stk.pop();
                }
            }
        }
        if(stk.empty())
            return true;
        return false;
    }
private:
    stack<char> stk;
    
};