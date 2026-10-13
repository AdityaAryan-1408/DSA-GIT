class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long n = nums.size();
        vector<long long> res(n);
        for (long long i = 0; i < n; i++) {
            res[i] = abs(nums[i]);
        }
        sort(res.begin(), res.end());
        long long i = 0, j = n - 1;
        long long total = 0;
        while (i <= j) {
            if (i == j) {
                total += res[i] * res[i];
                i++, j--;
                continue;
            }
            long long r = (res[j] * res[j]) - (res[i] * res[i]);
            total += r;
            j--;
            i++;
        }
        return total;
    }
};