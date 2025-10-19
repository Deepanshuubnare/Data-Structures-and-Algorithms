class Solution {
public:
    int findNthDigit(int n) {
            long long len = 1;

        long long count = 9;
    long long start = 1;

    while (n > len * count) {
        n -= len * count;
        len++;
        count *= 10;
        start *= 10;
    }

    long long num = start + (n - 1) / len;
    std::string s = std::to_string(num);
    return s[(n - 1) % len] - '0';
    }
};