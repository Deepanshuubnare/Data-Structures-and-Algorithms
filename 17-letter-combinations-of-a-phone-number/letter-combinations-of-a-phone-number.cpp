class Solution {
public:
 void f(int index, string &digits, vector<string> &mapping,
                   string &current, vector<string> &result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';
        for (char ch : mapping[digit]) {
            current.push_back(ch);
            f(index + 1, digits, mapping, current, result);
            current.pop_back(); // backtrack
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mapping = {
            "",    "",    "abc",  "def", // 0,1,2,3
            "ghi", "jkl", "mno",  "pqrs", // 4,5,6,7
            "tuv", "wxyz" // 8,9
        };

        vector<string> result;
        string current;
        f(0, digits, mapping, current, result);
        return result;
    }
};