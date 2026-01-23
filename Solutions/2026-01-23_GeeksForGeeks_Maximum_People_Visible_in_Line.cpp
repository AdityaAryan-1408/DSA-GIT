/*

Problem Name   : Maximum People Visible in Line
Platform       : GeeksForGeeks
Topic          : Array, Stack
Problem Link   : https://www.geeksforgeeks.org/problems/maximum-people-visible-in-a-line/1
Type           : POTD
Difficulty     : Medium
Date Solved    : 2026-01-23

*/

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int n;

    int ltr(vector<int>& arr, int ind) {
        int count = 0;
        for (int i = ind + 1; i < n; i++) {
            if (arr[i] < arr[ind]) {
                count++;
            } else {
                break;
            }
        }
        return count;
    }

    int rtl(vector<int>& arr, int ind) {
        int count = 0;
        for (int i = ind - 1; i >= 0; i--) {
            if (arr[i] < arr[ind]) {
                count++;
            } else {
                break;
            }
        }
        return count;
    }

    int maxPeopleApproachArr(vector<int>& arr) {  // Gives TLE
        n = arr.size();
        int maxP = 0;
        for (int i = 0; i < n; i++) {
            maxP = max(maxP, ltr(arr, i) + rtl(arr, i) + 1);
        }
        return maxP;
    }
    int maxPeople(vector<int>& arr) {  // Stack O(N)
        int n = arr.size();
        vector<int> leftBoundary(n, -1);
        vector<int> rightBoundary(n, n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                leftBoundary[i] = st.top();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                rightBoundary[i] = st.top();
            }
            st.push(i);
        }

        int maxP = 0;
        for (int i = 0; i < n; i++) {
            int leftCount = i - leftBoundary[i] - 1;
            int rightCount = rightBoundary[i] - i - 1;
            maxP = max(maxP, leftCount + rightCount + 1);
        }

        return maxP;
    }
};

int main() {
    Solution s;
    vector<int> arr = {6, 2, 5, 4, 1, 6};
    cout << s.maxPeople(arr) << endl;
    return 0;
}