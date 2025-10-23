class Solution {
public:
int getMin(const vector<int>& a) {
    return *min_element(a.begin(), a.end());
}

int getMax(const vector<int>& a) {
    return *max_element(a.begin(), a.end());
}

void fillBuckets(const vector<int>& a, int g, int mn,
                 vector<int>& lo, vector<int>& hi, vector<bool>& ok) {
    for (int x : a) {
        int id = (x - mn) / g;
        lo[id] = min(lo[id], x);
        hi[id] = max(hi[id], x);
        ok[id] = true;
    }
}

int calcGap(const vector<int>& lo, const vector<int>& hi,
            const vector<bool>& ok, int mn) {
    int p = mn, res = 0;
    for (int i = 0; i < ok.size(); i++) {
        if (!ok[i]) continue;
        res = max(res, lo[i] - p);
        p = hi[i];
    }
    return res;
}
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
    if (n < 2) return 0;

    int mn = getMin(nums);
    int mx = getMax(nums);
    if (mn == mx) return 0;

    int g = max(1, (mx - mn) / (n - 1));
    int b = (mx - mn) / g + 1;

    vector<int> lo(b, INT_MAX), hi(b, INT_MIN);
    vector<bool> ok(b, false);

    fillBuckets(nums, g, mn, lo, hi, ok);
    return calcGap(lo, hi, ok, mn);
    }
};