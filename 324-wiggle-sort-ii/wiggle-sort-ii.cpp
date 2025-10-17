class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
    if (n <= 1) {
        return;
    }

    vector<int> sorted_nums = nums;
    sort(sorted_nums.begin(), sorted_nums.end());

    int mid = (n - 1) / 2;
    int right = n - 1;

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            nums[i] = sorted_nums[mid--];
        } else {
            nums[i] = sorted_nums[right--];
        }
    }
    }
    
};