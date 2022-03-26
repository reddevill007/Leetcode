/*
  912. Sort an Array
  Medium

  Given an array of integers nums, sort the array in ascending order.

  Example 1:
    Input: nums = [5,2,3,1]
    Output: [1,2,3,5]
    
  Example 2:
    Input: nums = [5,1,1,2,0,0]
    Output: [0,0,1,1,2,5]

  Constraints:
    1 <= nums.length <= 5 * 104
    -5 * 104 <= nums[i] <= 5 * 104
*/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};
