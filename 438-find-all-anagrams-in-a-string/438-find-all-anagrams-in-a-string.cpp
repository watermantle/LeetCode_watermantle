class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {};
        
        vector<int> res;
        vector<int> p_hm(26, 0);
        int n = p.size();
        for (char& c: p) p_hm[c - 'a']++;
        
        for (int i = 0; i < n; ++i) p_hm[s[i] - 'a']--;
        if (if_valid(p_hm)) res.push_back(0);
        
        for (int i = 0; i < s.size() - n; ++i) {
            p_hm[s[i] - 'a']++;
            p_hm[s[i + n] - 'a']--;
            if (if_valid(p_hm)) res.push_back(i + 1);
        }
        return res;
    }
private:
    bool if_valid(vector<int>& arr) {
        for (int& num: arr) {
            if (num != 0) return false;
        }
        return true;
    }
};