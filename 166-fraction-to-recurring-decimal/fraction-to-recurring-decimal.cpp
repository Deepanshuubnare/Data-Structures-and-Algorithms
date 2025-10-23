class Solution {
public:
    string fractionToDecimal(int num, int den) {
        if (num == 0) return "0";

    string res;
    if ((num < 0) ^ (den < 0)) res.push_back('-');

    long long a = llabs(num), b = llabs(den);
    res += to_string(a / b);

    long long rem = a % b;
    if (!rem) return res;

    res.push_back('.');
    unordered_map<long long, int> seen;

    while (rem) {
        if (seen.count(rem)) {
            res.insert(seen[rem], "(");
            res.push_back(')');
            return res;
        }
        seen[rem] = res.size();
        rem *= 10;
        res += to_string(rem / b);
        rem %= b;
    }
    return res;
    }
};