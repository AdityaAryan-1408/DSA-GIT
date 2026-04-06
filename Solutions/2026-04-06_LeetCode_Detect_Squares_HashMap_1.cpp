/*

Problem Name   : Detect Squares
Platform       : LeetCode
Topic          : Array, Hash Table, Design, Counting, Data Stream
Problem Link   : https://leetcode.com/problems/detect-squares/submissions/1970500269/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-06
Approach       : HashMap 1
Time           : O(1) for Add, O(N) for Count
Space          : O(N)

*/

class DetectSquares {
public:
    unordered_map<long, int> ptCnt;
    vector<vector<int>> pts;

    long getKey(int x, int y) {
        return (static_cast<long>(x) << 32 | static_cast<long>(y));
    }
    DetectSquares() {}

    void add(vector<int> point) {
        long key = getKey(point[0], point[1]);
        ptCnt[key]++;
        pts.push_back(point);
    }

    int count(vector<int> point) {
        int res = 0;
        int px = point[0], py = point[1];

        for (const auto& pt : pts) {
            int x = pt[0], y = pt[1];
            if (abs(py - y) != abs(px - x) || x == px || y == py)
                continue;
            res += ptCnt[getKey(x, py)] * ptCnt[getKey(px, y)];
        }
        return res;
    }
};
