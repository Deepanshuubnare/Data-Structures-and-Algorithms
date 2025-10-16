class Solution {
public:
    int romanToInt(string s) {
       unordered_map<char, int> romanMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int result = romanMap[s.back()];
        for (int i = s.length() - 2; i >= 0; i--) {
            int currentVal = romanMap[s[i]];
            int rightVal = romanMap[s[i + 1]];
            if (currentVal < rightVal) {
                result -= currentVal;
            } else {
                result += currentVal;
            }
        }

        return result; 
    }
};