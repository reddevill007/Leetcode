/*
  229. Majority Element II
  Medium

  Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.



  Example 1:
    Input: nums = [3,2,3]
    Output: [3]

  Example 2:
    Input: nums = [1]
    Output: [1]

  Example 3:
    Input: nums = [1,2]
    Output: [1,2]

  Constraints:
    1 <= nums.length <= 5 * 104
    -109 <= nums[i] <= 109
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1 = 0, n2 = 1, c1 = 0, c2 = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int x = nums[i];
            if(x == n1) c1++;
            else if(x == n2) c2++;
            else if(c1 == 0) {
                n1 = x;
                c1++;
            }
            else if(c2 == 0) {
                n2 = x;
                c2++;
            } 
            else {
                c1--;
                c2--;
            }
        }
        c1 = 0;
        c2 = 0;
        for(int x: nums) {
            if(x == n1) c1++;
            else if(x == n2) c2++;
        }
        vector <int> res;
        
        if(c1 > n / 3) res.push_back(n1);
        if(c2 > n / 3) res.push_back(n2);
        
        return res;
    }
};
