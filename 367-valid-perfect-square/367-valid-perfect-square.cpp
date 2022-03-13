class Solution {
public:
    bool isPerfectSquare(int num) {
        unsigned long long left = 1, right = num;
        
        while(left <= right){
            unsigned long long mid = left + (right - left) / 2;
            unsigned long long prod = mid * mid;
            if (prod == num) return true;
            else if (prod < num) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};