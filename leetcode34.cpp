/* 
  34. Find First and Last Position of Element in Sorted Array

  Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

  If target is not found in the array, return [-1, -1].

  You must write an algorithm with O(log n) runtime complexity.



  Example 1:

  Input: nums = [5,7,7,8,8,10], target = 8
  Output: [3,4]
  Example 2:

  Input: nums = [5,7,7,8,8,10], target = 6
  Output: [-1,-1]
  Example 3:

  Input: nums = [], target = 0
  Output: [-1,-1]
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return vector<int>{-1, -1};
        }
        vector<int> res;
        int left = 0, right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if (nums[left] == target) {
            res.push_back(left);
        } else if (nums[right] == target) {
            res.push_back(right);
        } else {
            return vector<int>{-1, -1};
        }
        
        left = 0, right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if (nums[right] == target) {
            res.push_back(right);
        } else if (nums[left] == target) {
            res.push_back(left);
        } 
        return res;
    }
};
