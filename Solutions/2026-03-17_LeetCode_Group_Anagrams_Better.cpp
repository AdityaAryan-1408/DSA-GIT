/*

Problem Name   : Group Anagrams
Platform       : LeetCode
Topic          : Array, Hash Table, String, Sorting
Problem Link   : https://leetcode.com/problems/group-anagrams/submissions/1951221059/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-17
Approach       : Better
Time           : O(nL)
Space          : O(nL)

*/

class Solution2 {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<int>> list;
        vector<string> check = strs;
        for (string& s : strs) {
            sort(s.begin(), s.end());
        }
        for (int i = 0; i < strs.size(); i++) {
            list[strs[i]].push_back(i);
        }
        vector<vector<string>> res;
        for (auto& [s, indices] : list) {
            vector<string> temp;
            for (int i : indices) {
                temp.push_back(check[i]);
            }
            res.push_back(temp);
        }
        return res;
    }
};

// TC = O(nLlogL+nLlogn) ~ O(nLlogL)
// SC = O(nL)
