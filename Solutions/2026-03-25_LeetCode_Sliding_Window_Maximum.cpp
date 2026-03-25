/*

Problem Name   : Sliding Window Maximum
Platform       : LeetCode
Topic          : Array, Queue, Sliding Window, Heap (Priority Queue), Monotonic Queue
Problem Link   : https://leetcode.com/problems/sliding-window-maximum/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-03-25
Time           : O(N)
Space          : O(K)

*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            // Step 1 - Make space for new element
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Step 2 - Pop smaller elements
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }

            // Step 3 - Push new element
            dq.push_back(i);

            // Step 4 - Get answer for current window
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
