/*
  41. First Missing Positive

  Given an unsorted integer array nums, return the smallest missing positive integer.

  You must implement an algorithm that runs in O(n) time and uses constant extra space.



  Example 1:
    Input: nums = [1,2,0]
    Output: 3
    
  Example 2:
    Input: nums = [3,4,-1,1]
    Output: 2
    
  Example 3:
    Input: nums = [7,8,9,11,12]
    Output: 1


  Constraints:
    1 <= nums.length <= 5 * 105
    -231 <= nums[i] <= 231 - 1
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool one = false;
        for(int x: nums) {
            if(x == 1) {
                one = true;
                break;
            }
        }
        if(!one) return 1;
        
        int n = nums.size();
        
        if(n == 1) return 2;
        
        for(int i = 0; i < n; i++)
            if(nums[i] <= 0 || nums[i] > n) nums[i] = 1;
        
        for(int i = 0; i < n; i++) {
            int x = abs(nums[i]);
            if(nums[x - 1] > 0) nums[x - 1] *= -1;
        }
        
        for(int i = 0; i < n; i++)
            if(nums[i] > 0) return i + 1;
        
        return n + 1;
    }
};
