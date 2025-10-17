class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        if (n < 3) {
            return false;
        }

        for (int i = 1; i <= n / 2; ++i) {
            for (int j = 1; max(i, j) <= n - i - j; ++j) {
                string s1 = num.substr(0, i);
                string s2 = num.substr(i, j);

                if ((s1.length() > 1 && s1[0] == '0') || (s2.length() > 1 && s2[0] == '0')) {
                    continue;
                }

                long long n1 = stoll(s1);
                long long n2 = stoll(s2);
                string remaining = num.substr(i + j);
                
                // This part of your logic is correct
                while (!remaining.empty()) {
                    long long current_sum = n1 + n2;
                    string sum_str = to_string(current_sum);

                    if (remaining.rfind(sum_str, 0) != 0) {
                        break;
                    }
                    
                    remaining = remaining.substr(sum_str.length());
                    n1 = n2;
                    n2 = current_sum;
                }

                if (remaining.empty()) {
                    return true;
                }
            }
        }
        
      
        return false; 
    }
    
};