/*

Problem Name   : Group Anagrams
Platform       : LeetCode
Topic          : Array, Hash Table, String, Sorting
Problem Link   : https://leetcode.com/problems/group-anagrams/submissions/1951221059/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-17
Approach       : Better2
Time           : O(nL)
Space          : O(nL)

*/

class Solution3 {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        for (int i = 0; i < n; i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(strs[i]);
        }

        for (auto& [s, v] : mp) {
            res.push_back(v);
        }
        return res;
    }
};

// TC = O(nLlogL)
// SC = O(nL)
