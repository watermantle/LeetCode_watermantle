class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res = 0;
        int curr = 0;
        if (values.size() == 2) return values[0] + values[1] - 1;
        
        for (int i = 0; i < values.size(); ++i) {
            res = max(res, curr + values[i] - i);
            if (values[i] + i > curr) curr = values[i] + i;
        }
        return res;
    }
};