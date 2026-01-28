/*

Problem Name   : Count Subset With Target Sum II
Platform       : GeeksForGeeks
Topic          : Dynamic Programming
Problem Link   : https://www.geeksforgeeks.org/problems/count-the-subset-with-sum-equal-to-k/1
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-28

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void genSums(int idx, int end, long long sum, vector<int>& arr,
                 vector<long long>& res) {
        if (idx == end) {
            res.push_back(sum);
            return;
        }
        genSums(idx + 1, end, sum, arr, res);
        genSums(idx + 1, end, sum + arr[idx], arr, res);
    }

    long long countSubset(vector<int>& arr, long long target) {
        int n = arr.size();
        int mid = n / 2;

        vector<long long> left, right;

        genSums(0, mid, 0, arr, left);
        genSums(mid, n, 0, arr, right);

        sort(right.begin(), right.end());

        long long ans = 0;
        for (long long x : left) {
            long long need = target - x;
            ans += upper_bound(right.begin(), right.end(), need) -
                   lower_bound(right.begin(), right.end(), need);
        }

        return ans;
    }
};

int main() {
    Solution s;

    return 0;
}