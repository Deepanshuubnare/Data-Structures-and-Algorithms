class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
    if (n == 0 || n < k) {
        return 0;
    }
    if (k <= 1) {
        return n;
    }

    unordered_map<char, int> counts;
    for (char c : s) {
        counts[c]++;
    }

    int split_idx = 0;
    while (split_idx < n && counts[s[split_idx]] >= k) {
        split_idx++;
    }

    if (split_idx == n) {
        return n;
    }

    int left = longestSubstring(s.substr(0, split_idx), k);
    
    while (split_idx < n && counts[s[split_idx]] < k) {
        split_idx++;
    }
    
    int right = longestSubstring(s.substr(split_idx), k);

    return max(left, right);
    }
};