class Solution {
public:
unordered_map<string, bool> memo;
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        if (s1 == s2) {
            return true;
        }

        string key = s1 + "#" + s2;
        if (memo.count(key)) {
            return memo[key];
        }

        string temp_s1 = s1;
        string temp_s2 = s2;
        sort(temp_s1.begin(), temp_s1.end());
        sort(temp_s2.begin(), temp_s2.end());
        if (temp_s1 != temp_s2) {
            return memo[key] = false;
        }

        int n = s1.length();
        for (int i = 1; i < n; i++) {
            bool no_swap = isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                           isScramble(s1.substr(i), s2.substr(i));

            if (no_swap) {
                return memo[key] = true;
            }

            bool swap = isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                        isScramble(s1.substr(i), s2.substr(0, n - i));

            if (swap) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }
};