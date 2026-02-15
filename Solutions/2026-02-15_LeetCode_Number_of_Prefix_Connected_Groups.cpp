/*

Problem Name   : Number of Prefix Connected Groups
Platform       : LeetCode
Topic          : Two Pointers, String
Problem Link   : https://leetcode.com/problems/number-of-prefix-connected-groups/description/
Type           : Contest
Difficulty     : Medium
Date Solved    : 2026-02-15

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Sorting and Two Pointers with 1 loop
    int prefixConnected(vector<string>& words, int k) {
        sort(words.begin(), words.end());
        int n = words.size();

        int groups = 0;
        int groupMem;
        int i = 0, j = 0;
        while (j < n) {
            if (words[j].size() < k) {
                i++;
                j++;
                continue;
            }

            string first = words[i].substr(0, k);
            string second = words[j].substr(0, k);

            if (first != second) {
                groupMem = j - i;
                if (groupMem >= 2) groups++;
                i = j;
                j = i - 1;
            }
            j++;
        }
        groupMem = j - i;
        if (groupMem >= 2) groups++;
        return groups;
    }
    // Sorting and Two Pointers with 2 loops
    int prefixConnected(vector<string>& words, int k) {
        sort(words.begin(), words.end());
        int n = words.size();
        int groups = 0;

        int i = 0;
        while (i < n) {
            // Skip invalid words (cannot be part of any group)
            if (words[i].size() < k) {
                i++;
                continue;
            }
            // Start a new block
            int j = i;
            string pref = words[i].substr(0, k);
            // Expand block while prefix matches and word is valid
            while (j < n && words[j].size() >= k &&
                   words[j].substr(0, k) == pref) {
                j++;
            }
            // Block is [i ... j-1]
            int blockSize = j - i;
            if (blockSize >= 2) groups++;
            // Jump to next block
            i = j;
        }
        return groups;
    }
    // Hashing with 1 loop
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        // Count prefix frequencies
        for (const string& w : words) {
            if (w.size() >= k) {
                string pref = w.substr(0, k);
                freq[pref]++;
            }
        }

        // Count groups
        int groups = 0;
        for (auto& p : freq) {
            if (p.second >= 2) groups++;
        }

        return groups;
    }
};

int main() {
    Solution s;

    return 0;
}