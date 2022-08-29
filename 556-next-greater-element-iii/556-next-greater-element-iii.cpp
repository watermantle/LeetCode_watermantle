class Solution {
public:
    int nextGreaterElement(int n) {
        string digits = to_string(n);
        next_permutation(begin(digits), end(digits));
        long long res = stoll(digits);
        return (res > INT_MAX || res <= n) ? -1 : res;
    }
};