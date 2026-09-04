class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffixMin(n);
        int prefixMax = nums[0];

        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }
        for (int i = 0; i < n; i++) {
            int maxVal = max(nums[i], prefixMax);
            if(maxVal != prefixMax){
                prefixMax = maxVal;
            }
            int minVal = suffixMin[i];
            int stable = abs(maxVal - minVal);
            if (stable <= k)
                return i;
        }
        return -1;
    }
};