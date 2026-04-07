/*

Problem Name   : Meeting Rooms
Platform       : GeeksForGeeks
Topic          : Sorting, Greedy, Arrays, Intervals
Problem Link   : https://www.geeksforgeeks.org/problems/attend-all-meetings/1
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-04-07
Time           : O(NlogN)
Space          : O(1)

*/

class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        sort(arr.begin(), arr.end());
        for(int i = 1; i< arr.size(); i++){
            if(arr[i][0] < arr[i - 1][1]) return false;
        }
        return true;
    }
};
