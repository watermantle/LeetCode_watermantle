class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        
        long long num;
        int left = 2, right = x / 2;
        
        while (left <= right){
            long mid = left + (right - left) / 2;
            num = mid * mid;
            if (num > x) right = mid - 1;
            if (num < x) left = mid + 1;
            if (num == x) return mid;
        }
        return right;
    }
};