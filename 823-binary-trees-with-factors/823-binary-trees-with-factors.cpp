class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        long mod = pow(10, 9) + 7;
        vector<long> dp(n, 1);
        sort(arr.begin(), arr.end());
        unordered_map<int, long> index;
        
        for (int i = 0; i < n; ++i) {
            index[arr[i]] = i;
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[i] % arr[j] == 0) {
                    long right = arr[i] / arr[j];
                    if (index.count(right)) {
                        dp[i] = (dp[i] + dp[j] * dp[index[right]]) % mod;
                    }
                }
            }
        }
        long res = 0;
        for (auto& num: dp) res += num;
        return int(res % mod);
    }
};