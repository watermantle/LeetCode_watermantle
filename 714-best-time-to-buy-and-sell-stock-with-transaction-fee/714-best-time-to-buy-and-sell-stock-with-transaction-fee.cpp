class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.size() == 1) return 0;
        int res = 0;
        int buyPrice = prices[0];
        
        for (int i = 1; i < prices.size(); ++i) {
            if (buyPrice > prices[i]) buyPrice = prices[i];
            else {
                int profit = prices[i] - buyPrice - fee;
                if (profit > 0) {
                    res += profit;
                    buyPrice = prices[i] - fee;
                }
            }
        }
        return res;
    }
};