class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = getSum(n);
        while (fast != 1 && fast != slow) {
            slow = getSum(slow);
            fast = getSum(getSum(fast));
            if (fast == 1) return true;
        }
        return fast == 1;
    }
private:
    int getSum(int n) {
        int sum = 0;
        while (n > 0) {
            int r = n % 10;
            sum += r * r;
            n /= 10;
        }
        return sum;
    }
};