/*
  32. Longest Valid Parentheses
  Hard

  7242

  248

  Add to List

  Share
  Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.



  Example 1:

  Input: s = "(()"
  Output: 2
  Explanation: The longest valid parentheses substring is "()".
  Example 2:

  Input: s = ")()())"
  Output: 4
  Explanation: The longest valid parentheses substring is "()()".
  Example 3:

  Input: s = ""
  Output: 0


  Constraints:

  0 <= s.length <= 3 * 104
  s[i] is '(', or ')'.
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> ind;
        ind.push(-1);
        int ans = 0;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '(') {
                ind.push(i);
            }
            else {
                ind.pop();
                if(ind.size() == 0) {
                    ind.push(i);
                }
                else {
                    ans = max(ans, i - ind.top());
                }
            }
        }
        
        return ans;
    }
};
