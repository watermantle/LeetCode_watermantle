class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        for (auto candy: candies) sum += candy;
        if (sum < k) return 0;
        
        long long low = 1, high = *max_element(candies.begin(), candies.end());
        int res;
        
        while (low <= high){
            long long mid = low + (high - low) / 2;
            
            if (helper(mid, candies, k)){
                res = mid;
                low = mid + 1;
            }else high = mid - 1;
        }
        return res;
    }
private:
    bool helper(long long pile_size, vector<int>& candies, long long k){
        long long count = 0;
        for (auto candy: candies){
            count += candy / pile_size;
        }
        return count >= k;
    }
};