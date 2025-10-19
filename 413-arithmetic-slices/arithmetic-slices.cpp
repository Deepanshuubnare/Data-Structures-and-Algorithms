class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) {
        return 0;
    }

    int total_count = 0;
    int current_streak = 0;

    for (int i = 2; i < nums.size(); ++i) {
        if ((long)nums[i] - nums[i-1] == (long)nums[i-1] - nums[i-2]) {
            current_streak++;
        } else {
            current_streak = 0;
        }
        total_count += current_streak;
    }

    return total_count;
    }
};