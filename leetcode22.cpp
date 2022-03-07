/* 
  Generate Parentheses Leetcode
  
  Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.



  Example 1:

  Input: n = 3
  Output: ["((()))","(()())","(())()","()(())","()()()"]
  Example 2:

  Input: n = 1
  Output: ["()"]
*/

class Solution {
public:
    void helpFun(vector<string> &res, int n, int openN, int closeN, string s) {
        if(openN == n && closeN == n) {
            res.push_back(s);
            return;
        }
        
        if(openN < n) {
            helpFun(res, n, openN+1, closeN, s + "(");
        }
        
        if(closeN < openN) {
            helpFun(res, n, openN, closeN+1, s + ")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int openN = 0, closeN = 0;
        helpFun(res, n, openN, closeN, "");
        return res;
    }
};
