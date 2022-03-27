/*
  7. Reverse Integer
  Medium

  Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

  Assume the environment does not allow you to store 64-bit integers (signed or unsigned).



  Example 1:
    Input: x = 123
    Output: 321
    
  Example 2:
    Input: x = -123
    Output: -321
    
  Example 3:
    Input: x = 120
    Output: 21


  Constraints:
    -231 <= x <= 231 - 1
*/

class Solution {
public:
     int reverse(int x) {
        int last=x%10;
        int rev=0;
        while(x!=0){
            last=x%10;
            if (rev>=INT_MAX/10){
                if (rev>INT_MAX/10){
                    return 0;
                }else{
                    if (last>7){
                      return 0;
                    }
                }
            }
            if (rev<=INT_MIN/10){
                if (rev<INT_MIN/10){
                    return 0;
                }else{
                    if (last<-8){
                        return 0;
                    }
                }
            }
            rev=rev*10+last;
            x=x/10;
        }
        return rev;
    }
};
