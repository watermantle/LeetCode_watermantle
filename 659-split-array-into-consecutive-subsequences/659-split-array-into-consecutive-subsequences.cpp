class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> store, end;
        for (int& num: nums) store[num]++;
        
        for (int& num: nums) {
            if (store[num] == 0) continue;
            store[num]--;
            if (end[num - 1] > 0) {
                end[num - 1]--;
                end[num]++;
            }
            else if (store[num + 1] > 0 && store[num + 2] > 0) {
                store[num + 1]--;
                store[num + 2]--;
                end[num + 2]++;
            }
            else return false;
        }
        return true;
    }
};