/*

Problem Name   : Word Ladder
Platform       : LeetCode
Topic          : Hash Table, String, Breadth-First Search
Problem Link   : https://leetcode.com/problems/word-ladder/submissions/1862760705/
Type           : Practice
Difficulty     : Hard
Date Solved    : 2026-05-24

*/

class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);
        while (!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (word == targetWord)
                return steps;
            for (int i = 0; i < word.size(); i++)
            {
                char og = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.find(word) != st.end())
                    {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = og;
            }
        }
        return 0;
    }
};
