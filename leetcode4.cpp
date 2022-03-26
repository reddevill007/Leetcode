/*
  4. Median of Two Sorted Arrays
  Hard

  Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

  The overall run time complexity should be O(log (m+n)).

  Example 1:
    Input: nums1 = [1,3], nums2 = [2]
    Output: 2.00000
    Explanation: merged array = [1,2,3] and median is 2.
    
  Example 2:
    Input: nums1 = [1,2], nums2 = [3,4]
    Output: 2.50000
    Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


  Constraints:
    nums1.length == m
    nums2.length == n
    0 <= m <= 1000
    0 <= n <= 1000
    1 <= m + n <= 2000
    -106 <= nums1[i], nums2[i] <= 106
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int x = n + m;
        double median = 0;
        
        vector<int> v;
        
        for(int i = 0; i < n; i++)
            v.push_back(nums1[i]);
        
        for(int i = 0; i < m; i++)
            v.push_back(nums2[i]);
        
        sort(v.begin(), v.end());
        
        if(x % 2 == 0)
            median = (v[(x - 1) / 2] + v[x / 2]) / 2.0;
        else
            median = v[x / 2]; 
        return median;
    }
};
