/*

Problem Name   : Group Anagrams
Platform       : LeetCode
Topic          : Array, Hash Table, String, Sorting
Problem Link   : https://leetcode.com/problems/group-anagrams/submissions/1951221059/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-17
Approach       : Optimal
Time           : O(nL)
Space          : O(nL)

*/

class Solution4 {
   public:
    /*
   Considering the constraint that all characters are lower case english letters, we can create a vector of 26 size for
   each letter.
   For each string, we can count the frequency of each character and store it in the vector. 
   Now from the vector, we create a string taking all characters who are not 0 frequency. So for example, for "eat",
   we will get a-1, e-1, t-1, and then the resultant string will be aet. Now we clear the vector. Repeating this for each
   string, we can then put the strings in a map and create a similar output as the previous solution.
   This approach saves the time for sorting the string.

   TC = O(N * L) where N is the number of strings and L is the length of the longest string. 
   We are iterating through each string and counting the frequency of characters which takes O(L) time.

   SC = O(N * L) in the worst case when all strings are different and we have to store all of them in the map.
   */

    string generateWord(string& s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        string res = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                res += string(freq[i], i + 'a');
            }
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        for (int i = 0; i < n; i++) {
            string word = strs[i];
            string new_word = generateWord(word);
            mp[new_word].push_back(word);
        }
        for (const auto& [key, value] : mp) {
            res.push_back(value);
        }
        return res;
    }
};
