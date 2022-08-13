class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int price_buy = INT_MAX;
        
        for (int i = 0; i < prices.size(); ++i) {
            int price = prices[i];
            if (price < price_buy) price_buy = price;
            else {
                res = max(res, price - price_buy);
            }
        }
        return res;
    }
};