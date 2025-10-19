class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long arraySum = 0;
        long long currentF = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            arraySum += nums[i];
            currentF += (long long)i * nums[i];
        }

        long long maxF = currentF;

        for (int k = 1; k < n; k++) {
            currentF = currentF + arraySum - (long long)n * nums[n - k];
            if (currentF > maxF) {
                maxF = currentF;
            }
        }
        
        return (int)maxF;
    }
};