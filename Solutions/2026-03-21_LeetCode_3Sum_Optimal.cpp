/*

Problem Name   : 3Sum
Platform       : LeetCode
Topic          : Array, Two Pointers, Sorting
Problem Link   : https://leetcode.com/problems/3sum/submissions/1955014150/
Type           : Practice
Difficulty     : Medium
Date Solved    : 2026-03-21
Approach       : Optimal
Time           : O(Nlog N)
Space          : O(No. of Unique triplets)

*/

vector<vector<int>> threeSumOptimal(vector<int> &nums)
{
    // TC = O(Nlog N) - sort + O(N^2)
    // SC = O(No. of Unique triplets)
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        // remove duplicates:
        if (i != 0 && nums[i] == nums[i - 1])
            continue;

        // moving 2 pointers:
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                // skip the duplicates:
                while (j < k && nums[j] == nums[j - 1])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            }
        }
    }
    return ans;
}
