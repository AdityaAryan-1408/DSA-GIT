/*

Problem Name   : 3Sum
Platform       : LeetCode
Topic          : Array, Two Pointers, Sorting
Problem Link   : https://leetcode.com/problems/3sum/submissions/1955014150/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-21
Approach       : Better
Time           : O(Nlog N)
Space          : O(No. of Unique triplets)

*/

vector<vector<int>> threeSumBetter(vector<int> &nums)
{
    // TC  O(N^2 * Log M) - Gives TLE on LC
    // SC = O(N) + O(2 * No. of Unique Triplets)
    int n = nums.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            int third = -(nums[i] + nums[j]);
            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
