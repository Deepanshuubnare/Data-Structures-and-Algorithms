class Solution {
public:
    int numDecodings(string s) {
       if (s.empty() || s[0] == '0') {
            return 0;
        }

        int two_back = 1;
        int one_back = 1;

        for (int i = 1; i < s.length(); i++) {
            int current = 0;

            if (s[i] != '0') {
                current = one_back;
            }

            int two_digit_val = stoi(s.substr(i - 1, 2));
            if (two_digit_val >= 10 && two_digit_val <= 26) {
                current += two_back;
            }

            two_back = one_back;
            one_back = current;
        }

        return one_back;
    }
};