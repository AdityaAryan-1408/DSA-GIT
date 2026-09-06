class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    int helper(int i, int j, string& s, string& p) {
        if (j == m) {
            return 1;
        }
        if (i == n) {
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == p[j]) {
            return dp[i][j] =
                       helper(i + 1, j + 1, s, p) + helper(i + 1, j, s, p);
        } else {
            return dp[i][j] = helper(i + 1, j, s, p);
        }
    }
    int numDistinct(string& s, string& p) {
        n = s.size(), m = p.size();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        return helper(0, 0, s, p);
    }
};