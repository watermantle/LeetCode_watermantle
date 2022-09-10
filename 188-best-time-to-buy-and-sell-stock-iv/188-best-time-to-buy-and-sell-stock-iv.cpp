class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        if (n <= 0 || k <= 0) return 0;
        
        if (2 * k > n) {
            int res = 0;
            for (int i = 1; i < n; ++i) {
                res += max(0, prices[i] - prices[i - 1]);
            }
            return res;
        }
        
        vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
        
        for (int& price: prices) {
            for (int i = 1; i <= k; ++i) {
                buy[i] = max(buy[i], sell[i - 1] - price);
                sell[i] = max(sell[i], buy[i] + price);
            }
        }
        return sell[k];
    }
};