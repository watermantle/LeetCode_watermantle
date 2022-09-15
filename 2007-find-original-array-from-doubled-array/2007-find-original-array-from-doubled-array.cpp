class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2) return {};
        
        sort(changed.begin(), changed.end());
        unordered_map<int, int> mp;
        
        for (int& num: changed) mp[num]++;
        
        vector<int> res;
        for (int& num: changed) {
            if (mp[num]) {
                mp[num]--;
                int doubleNum = num * 2;
                if (mp[doubleNum] > 0) {
                    mp[doubleNum]--;
                    res.push_back(num);
                }
                else return {};
            }
        }
        return res;
    }
};