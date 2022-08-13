class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int price_buy = INT_MAX;
        
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < price_buy) price_buy = prices[i];
            else {
                res = max(res, prices[i] - price_buy);
            }
        }
        return res;
    }
};