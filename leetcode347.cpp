/*
    Top K Frequent Elements - LeetCode
    
    
    Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

    Example 1:

    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]
    Example 2:

    Input: nums = [1], k = 1
    Output: [1]
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
		for (int x : nums) 	cnt[x] ++;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		for (auto &x : cnt) {
			if (q.size() < k)
				q.push(make_pair(x.second, x.first));
			else {
				if (q.top().first < x.second) {
					q.pop();
					q.push(make_pair(x.second, x.first));
				}
			}
		}
		vector<int> ans;
		while (!q.empty()) {
			ans.push_back(q.top().second);
			q.pop();
		}
		return ans;
    }
};
