class Solution {
public:
    string multiply(string num1, string num2) {
         if (num1 == "0" || num2 == "0") {
        return "0";
    }

    int m = num1.length();
    int n = num2.length();
 
    vector<int> result_vec(m + n, 0);
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int digit1 = num1[i] - '0';
            int digit2 = num2[j] - '0';
         int product = digit1 * digit2;
            int p1 = i + j;     // Position for the 'carry' part
            int p2 = i + j + 1; // Position for the 'units' part
            int sum = product + result_vec[p2];
            result_vec[p2] = sum % 10;       // The unit digit of the sum
            result_vec[p1] += sum / 10;      // Add the carry to the next position
        }
    }
    string result_str = "";
    int i = 0;
    while (i < result_vec.size() && result_vec[i] == 0) {
        i++;
    }
    while (i < result_vec.size()) {
        result_str += to_string(result_vec[i]);
        i++;
    }

    return result_str;
    }
};