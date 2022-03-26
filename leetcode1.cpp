/*
  1. Two Sum
  Easy

  Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

  You may assume that each input would have exactly one solution, and you may not use the same element twice.

  You can return the answer in any order.



  Example 1:
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
    
  Example 2:
    Input: nums = [3,2,4], target = 6
    Output: [1,2]
    
  Example 3:
    Input: nums = [3,3], target = 6
    Output: [0,1]
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int n = a.size();
        for(int i = 0 ; i < n - 1 ; i++)
            for(int j = i + 1 ; j < n ; j++)
            {
                if(a[i] + a[j] == target)
                    return {i , j};
            }
        return {};
    }
};
