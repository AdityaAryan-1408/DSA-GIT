class Solution {
public:
    vector<int> commas = vector<int>(17);
    void setCommas() {
        for (int i = 0; i <= 16; i++) {
            commas[i] = (i - 1) / 3;
        }
    }
    long long generateMax(int len) {
        long long res = 0;
        while (len != 0) {
            res = res * 10 + 9;
            len--;
        }
        return res;
    }
    long long power10(int n) {
        long long res = 1;
        while (n--) {
            res *= 10;
        }
        return res;
    }
    int lenCount(long long n) {
        int len = 0;
        while (n != 0) {
            len++;
            n /= 10;
        }
        return len;
    }
    long long countCommas(long long n) {
        if (n < 3)
            return 0;
        setCommas();
        int len = lenCount(n);
        long long result = 0;
        result = result + ((n - power10(len - 1) + 1) * commas[len]);
        len--;
        while (len > 3) {
            long long maxLen = generateMax(len);
            long long p10 = power10(len - 1);
            result += (maxLen - p10 + 1) * commas[len];
            len--;
        }
        return result;
    }
};