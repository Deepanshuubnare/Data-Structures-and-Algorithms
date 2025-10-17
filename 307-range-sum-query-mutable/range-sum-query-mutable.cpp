class NumArray {
    vector<int> tree;
    int n;

    void build(const vector<int>& nums, int treeIndex, int low, int high) {
        if (low == high) {
            tree[treeIndex] = nums[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(nums, 2 * treeIndex + 1, low, mid);
        build(nums, 2 * treeIndex + 2, mid + 1, high);
        tree[treeIndex] = tree[2 * treeIndex + 1] + tree[2 * treeIndex + 2];
    }

    void update_tree(int treeIndex, int low, int high, int arrIndex, int val) {
        if (low == high) {
            tree[treeIndex] = val;
            return;
        }
        int mid = low + (high - low) / 2;
        if (arrIndex <= mid) {
            update_tree(2 * treeIndex + 1, low, mid, arrIndex, val);
        } else {
            update_tree(2 * treeIndex + 2, mid + 1, high, arrIndex, val);
        }
        tree[treeIndex] = tree[2 * treeIndex + 1] + tree[2 * treeIndex + 2];
    }

    int query(int treeIndex, int low, int high, int query_low, int query_high) {
        if (low > query_high || high < query_low) {
            return 0;
        }
        if (low >= query_low && high <= query_high) {
            return tree[treeIndex];
        }
        int mid = low + (high - low) / 2;
        int left_sum = query(2 * treeIndex + 1, low, mid, query_low, query_high);
        int right_sum = query(2 * treeIndex + 2, mid + 1, high, query_low, query_high);
        return left_sum + right_sum;
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        if (n == 0) return;
        tree.resize(4 * n);
        build(nums, 0, 0, n - 1);
    }
    
    void update(int index, int val) {
        if (n == 0) return;
        update_tree(0, 0, n - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        if (n == 0) return 0;
        return query(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */