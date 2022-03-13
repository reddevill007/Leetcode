/*
  20. Valid Parentheses
  Easy

  Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

  An input string is valid if:

  Open brackets must be closed by the same type of brackets.
  Open brackets must be closed in the correct order.


  Example 1:

  Input: s = "()"
  Output: true
  Example 2:

  Input: s = "()[]{}"
  Output: true
  Example 3:

  Input: s = "(]"
  Output: false


  Constraints:
    1 <= s.length <= 104
    s consists of parentheses only '()[]{}'.
*/

class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        int len = str.length();
        for(int i = 0; i < len; i++) {
            if(str[i] == '(' || str[i] == '{' || str[i] == '[')
                s.push(str[i]);
            else if(str[i] == ')' || str[i] == '}' || str[i] == ']') {
                if(s.empty())
                    return false;
                else if(str[i] == ')' && s.top() != '(')
                    return false;
                else if(str[i] == '}' && s.top() != '{')
                    return false;
                else if(str[i] == ']' && s.top() != '[')
                    return false;
                else 
                    s.pop();
            }
        }
        if(s.empty()) return true;
        else return false;
    }
};
