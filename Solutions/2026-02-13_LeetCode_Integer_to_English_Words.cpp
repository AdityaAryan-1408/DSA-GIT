/*

Problem Name   : Integer to English Words
Platform       : LeetCode
Topic          : Strings
Problem Link   : https://leetcode.com/problems/integer-to-english-words/description/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-02-13

*/

#include <bits/stdc++.h>
using namespace std;

class Solution1 {
   public:
    map<int, string> numToWord = {{1, "One"},
                                  {2, "Two"},
                                  {3, "Three"},
                                  {4, "Four"},
                                  {5, "Five"},
                                  {6, "Six"},
                                  {7, "Seven"},
                                  {8, "Eight"},
                                  {9, "Nine"},
                                  {10, "Ten"},
                                  {11, "Eleven"},
                                  {12, "Twelve"},
                                  {13, "Thirteen"},
                                  {14, "Fourteen"},
                                  {15, "Fifteen"},
                                  {16, "Sixteen"},
                                  {17, "Seventeen"},
                                  {18, "Eighteen"},
                                  {19, "Nineteen"},
                                  {20, "Twenty"},
                                  {30, "Thirty"},
                                  {40, "Forty"},
                                  {50, "Fifty"},
                                  {60, "Sixty"},
                                  {70, "Seventy"},
                                  {80, "Eighty"},
                                  {90, "Ninety"},
                                  {100, "Hundred"},
                                  {1000, "Thousand"},
                                  {1000000, "Million"},
                                  {1000000000, "Billion"}};

    map<int, int> lenToTen = {{1, 1},          {2, 10},       {3, 100},
                              {4, 1000},       {5, 10000},    {6, 100000},
                              {7, 1000000},    {8, 10000000}, {9, 100000000},
                              {10, 1000000000}};

    map<int, string> lenToUnit = {
        {1, ""}, {2, "Thousand"}, {3, "Million"}, {4, "Billion"}};

    string hundred(int num) {
        if (num < 100) {
            if (num <= 20) {
                return numToWord[num];
            } else {
                int digit = num / 10 * 10;
                if (num % 10 == 0) return numToWord[digit];
                return numToWord[digit] + " " + numToWord[num % 10];
            }
        }

        string res = "";
        int digit = num / 100;

        res += numToWord[digit] + " " + numToWord[100];
        num %= 100;

        if (num == 0) return res;

        res += " ";

        if (num <= 20) {
            res += numToWord[num];
        } else {
            digit = num / 10 * 10;
            if (num % 10 == 0)
                res += numToWord[digit];
            else
                res += numToWord[digit] + " " + numToWord[num % 10];
        }

        return res;
    }

    string trim(string s) {
        int last = s.size() - 1;
        while (last >= 0 && s[last] == ' ') {
            s.pop_back();
            last--;
        }
        return s;
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";

        if (num < 10) {
            return numToWord[num];
        }

        if (num < 1000) {
            return hundred(num);
        }

        string res = "";
        int block = 1;

        while (num > 0) {
            int lastThreeDigits = num % 1000;

            if (lastThreeDigits > 0) {
                string part = hundred(lastThreeDigits);

                if (lenToUnit[block] != "") part += " " + lenToUnit[block];

                if (res != "")
                    res = part + " " + res;
                else
                    res = part;
            }

            num /= 1000;
            block++;
        }

        return res;
    }
};

class Solution2 {
   public:
    string numbersTill20[21] = {
        "Zero",     "One ",     "Two ",       "Three ",    "Four ",
        "Five ",    "Six ",     "Seven ",     "Eight ",    "Nine ",
        "Ten ",     "Eleven ",  "Twelve ",    "Thirteen ", "Fourteen ",
        "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen ",
        "Twenty "};

    string multiplesOf10[8] = {"Twenty ", "Thirty ",  "Forty ",  "Fifty ",
                               "Sixty ",  "Seventy ", "Eighty ", "Ninety "};

    string specialNames[4] = {"Hundred ", "Thousand ", "Million ", "Billion "};

    string getThreeDigitName(int num) {
        if (num == 0) return "";

        string ans = "";
        if (num / 100 != 0) {
            ans += numbersTill20[num / 100];
            ans += specialNames[0];
            num %= 100;
        }
        if (num == 0) return ans;

        if (num < 21) {
            ans += numbersTill20[num];
        } else {
            ans += multiplesOf10[num / 10 - 2];
            if (num % 10 != 0) ans += numbersTill20[num % 10];
        }
        return ans;
    }

    string numberToWords(int num) {
        if (num == 0) return numbersTill20[0];

        vector<string> ans;
        int i = 1;
        while (num) {
            ans.push_back(getThreeDigitName(num % 1000));
            num /= 1000;
            if (num % 1000) {
                ans.push_back(specialNames[i]);
            }
            i++;
        }
        string answer = "";
        for (int i = ans.size() - 1; i >= 0; i--) {
            answer += ans[i];
        }
        answer.pop_back();
        return answer;
    }
};
int main() { return 0; }