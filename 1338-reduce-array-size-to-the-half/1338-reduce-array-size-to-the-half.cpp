class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> map;
        for (int& num: arr) map[num]++;
        
        int res = 0;
        priority_queue<int> pq;
        for (auto& item: map) pq.push(item.second);
        
        int memo = 0;
        while (2 * memo < n) {
            memo += pq.top();
            pq.pop();
            res++;
        }
        return res;
    }
};