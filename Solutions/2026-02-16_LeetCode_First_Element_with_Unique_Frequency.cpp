/*

Problem Name   : First Element with Unique Frequency
Platform       : LeetCode
Topic          : Hashing
Problem Link   : https://leetcode.com/problems/first-element-with-unique-frequency/description/
Type           : Contest
Difficulty     : Medium
Date Solved    : 2026-02-16

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> numFreq;          // num -> freq
        unordered_map<int, vector<int>> freqNum;  // freq -> nums

        for (int x : nums) numFreq[x]++;
        for (auto& [num, freq] : numFreq) {
            freqNum[freq].push_back(num);
        }

        vector<int> uniqueFreqs;
        for (auto& [freq, nums] : freqNum) {
            if (nums.size() == 1) {
                uniqueFreqs.push_back(nums[0]);
            }
        }

        if (uniqueFreqs.empty()) return -1;

        for (int i = 0; i < uniqueFreqs.size(); ++i) {
            cout << uniqueFreqs[i] << " ";
        }
        cout << endl;
        int minIndex = INT_MAX;
        for (int x : uniqueFreqs) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == x) {
                    minIndex = min(minIndex, i);
                    break;
                }
            }
        }
        return minIndex == INT_MAX ? -1 : nums[minIndex];
    }

    int firstUniqueFreq2(vector<int>& nums) {
        unordered_map<int, pair<int, int>>
            numFreq;  // num -> (freq, firstIndex)
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (numFreq.find(num) == numFreq.end()) {
                numFreq[num] = {1, i};
            } else {
                numFreq[num].first++;
            }
        }

        unordered_map<int, int>
            freqNum;  // freq -> count of nums with this freq
        for (auto& p : numFreq) {
            int freq = p.second.first;
            freqNum[freq]++;
        }

        int minIndex = INT_MAX;
        for (auto& p : numFreq) {
            int num = p.first;
            int freq = p.second.first;
            int index = p.second.second;
            if (freqNum[freq] == 1) {
                minIndex = min(minIndex, index);
            }
        }
        return minIndex == INT_MAX ? -1 : nums[minIndex];
    }
};

int main() {
    Solution s;
    vector<int> nums = {10, 20, 30, 30};
    cout << s.firstUniqueFreq2(nums) << endl;
    return 0;
}