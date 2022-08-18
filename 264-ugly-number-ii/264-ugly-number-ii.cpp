class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(n, 0);
        res[0] = 1;
        int idx2 = 0, idx3 = 0, idx5 = 0;
        
        for (int i = 1; i < n; ++i) {
            int ugly = min(min(2 * res[idx2], 3 * res[idx3]), 5 * res[idx5]);
            if (ugly == 2 * res[idx2]) res[i] = 2 * res[idx2++];
            if (ugly == 3 * res[idx3]) res[i] = 3 * res[idx3++];
            if (ugly == 5 * res[idx5]) res[i] = 5 * res[idx5++];
        }
        return res[n - 1];
    }
};