/*

Problem Name   : Sort012s
Platform       : GeeksForGeeks
Topic          : Arrays
Problem Link   :
https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1 Type
: POTD Difficulty     : Medium Date Solved    : 2026-01-04

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void sort012(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main() {
    Solution s;

    return 0;
}