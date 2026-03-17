/*

Problem Name   : Group Anagrams
Platform       : LeetCode
Topic          : Array, Hash Table, String, Sorting
Problem Link   : https://leetcode.com/problems/group-anagrams/submissions/1951221059/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-17
Approach       : Brute Force
Time           : O(nL)
Space          : O(nL)

*/

class Solution1 {  // TLE
   public:
    int n;
    map<string, vector<int>> memo;  // Memoization for storing the hash of strings to avoid recomputation
    vector<int> genHash(string& s) {  // O(Len of string, upto 100)
        if (memo.count(s)) return memo[s];
        vector<int> hash(26, 0);
        for (char x : s) {
            hash[x - 'a']++;
        }
        return memo[s] = hash;
    }

    bool isAnagram(vector<int>& hash, string next) {  // O(26)
        vector<int> comp = genHash(next);
        for (int i = 0; i < 26; i++) {
            if (hash[i] != comp[i]) return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(
        vector<string>&strs) {  // overall O(nlogn) + O(n^2 * L) where n is the number of strings and L is the length of the longest string
        if (strs.empty()) return {{}};
        sort(strs.begin(),strs.end());  // O(nlogn) Sorting is not needed as checked array is used to avoid duplicates but it is done to get the output in sorted order as shown in the example test cases.
        n = strs.size();
        vector<vector<string>> res;
        vector<int> checked(n, 0);
        for (int i = 0; i < n; i++) {  // O(n)
            string curr = strs[i];
            vector<string> temp;
            if (checked[i] != 1) temp.push_back(curr);
            checked[i] = 1;
            vector<int> currHash = genHash(curr);
            for (int j = i + 1; j < n; j++) {  // O(n)
                if (checked[j] != 1 && isAnagram(currHash, strs[j])) {
                    temp.push_back(strs[j]);
                    checked[j] = 1;
                }
            }
            if (!temp.empty()) res.push_back(temp);
        }
        return res;
    }
};

// TC = O(n2+nL)≈O(n2)​
// SC = O(nL)
