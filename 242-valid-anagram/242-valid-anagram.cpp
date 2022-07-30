class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> record(26, 0);
        for (char& c_s: s) record[c_s - 'a']++;
        for (char& c_t: t) record[c_t - 'a']--;
             
        for (int& num: record) {
            if (num != 0) return false;
        }
        return true;
    }
};