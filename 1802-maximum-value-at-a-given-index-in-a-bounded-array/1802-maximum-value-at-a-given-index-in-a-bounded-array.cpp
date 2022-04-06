class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        int left = 0, right = maxSum;
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (check(n, index, mid) <= maxSum) {
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        return left;
    };
private:
    long check(int n, int index, int a){
        int b = max(a - index, 0);
        long res = long(a + b) * (a - b + 1) / 2;
        b = max(a - (n - 1 - index), 0);
        res += long(a + b) * (a - b + 1) / 2;
        return res - a;
    }
};