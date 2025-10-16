class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        factorial[i] = factorial[i - 1] * i;
    }

    vector<int> numbers(n);
    iota(numbers.begin(), numbers.end(), 1);

    string result = "";
    k--; 

    for (int i = n; i >= 1; i--) {
        int index = k / factorial[i - 1];
        result += to_string(numbers[index]);
        numbers.erase(numbers.begin() + index);
        k %= factorial[i - 1];
    }

    return result;
    }
};