/*

Problem Name   : Encode Decode Strings
Platform       : GeeksForGeeks
Topic          : String, Array
Problem Link   : https://www.geeksforgeeks.org/problems/encode-and-decode-strings/1
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-17
Approach       : Alternative
Time           : O(N)
Space          : O(N)

*/

class Solution2 {
   public:
    string encode(vector<string>& s) {
        string res = "";
        for (string x : s) {
            res += to_string(x.size()) + "_" + x;
        }
        return res;
    }
    vector<string> decode(string& s) {
        int n = s.size();
        int i = 0;
        vector<string> dec;

        while (i < n) {
            int j = i;
            while (s[j] != '_') {
                j++;
            }
            int len = stoi(s.substr(i, j - i));
            string temp = s.substr(j + 1, len);
            dec.push_back(temp);
            i = j + 1 + len;
        }
        return dec;
    }
};

// TC = O(N)
// SC = O(N)
