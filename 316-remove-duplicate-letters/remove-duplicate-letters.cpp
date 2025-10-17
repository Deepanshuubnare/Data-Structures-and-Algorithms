class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26, 0);
    for (int i = 0; i < s.length(); i++) {
        lastIndex[s[i] - 'a'] = i;
    }
    
    vector<bool> seen(26, false);
    string result;
    
    for (int i = 0; i < s.length(); i++) {
        char currentChar = s[i];
        if (seen[currentChar - 'a']) {
            continue;
        }
        
 while (!result.empty() && currentChar < result.back() && i < lastIndex[result.back() - 'a']) {
            seen[result.back() - 'a'] = false;
            result.pop_back();
        }
        
        result.push_back(currentChar);
        seen[currentChar - 'a'] = true;
    }
    
    return result;
    }
};