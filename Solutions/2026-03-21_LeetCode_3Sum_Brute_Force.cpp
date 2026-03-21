/*

Problem Name   : 3Sum
Platform       : LeetCode
Topic          : Array, Two Pointers, Sorting
Problem Link   : https://leetcode.com/problems/3sum/submissions/1955014150/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-21
Approach       : Brute Force
Time           : O(Nlog N)
Space          : O(No. of Unique triplets)

*/

vector<vector<int>> threeSumBrute(vector<int> &nums)
{
    // TC = O(N^3) + O(log (No. of Unique elements))
    // SC = 2 * O(No. of triplets)
    set<vector<int>> st;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
