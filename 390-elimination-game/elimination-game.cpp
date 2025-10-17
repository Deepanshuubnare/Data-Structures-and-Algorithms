class Solution {
public:
    int lastRemaining(int n) {
        int remaining = n;
    int head = 1;
    int step = 1;
    bool from_left = true;

    while (remaining > 1) {
        if (from_left || remaining % 2 == 1) {
            head = head + step;
        }
        remaining = remaining / 2;
        step = step * 2;
        from_left = !from_left;
    }
    return head;
    }
};