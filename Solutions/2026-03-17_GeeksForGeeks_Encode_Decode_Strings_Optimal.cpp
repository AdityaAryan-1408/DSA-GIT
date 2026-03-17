/*

Problem Name   : Encode Decode Strings
Platform       : GeeksForGeeks
Topic          : String, Array
Problem Link   : https://www.geeksforgeeks.org/problems/encode-and-decode-strings/1
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-17
Approach       : Optimal
Time           : O(N)
Space          : O(N)

*/

class Solution {
  public:
    string encode(vector<string>& s) {
        string res = "";
        for (string x : s) {
            res += x + ":;";
        }
        return res;
    }

    vector<string> decode(string& s) {
        int n = s.size();
        vector<string> res;
        for (int i = 0; i < n; i++) {
            string temp = "";
            while (i < n && s[i] != ':' && s[i + 1] != ';') {
                temp += s[i];
                i++;
            }
            res.push_back(temp);
            i += 1;
        }
        return res;
    }
};

// TC = O(N)
// SC = O(N)
