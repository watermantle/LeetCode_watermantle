class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int& num: nums) mp[num]++;
        
        priority_queue<pair<int, int>> pq;
        for (auto& item: mp) pq.push({item.second, item.first});
        
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};