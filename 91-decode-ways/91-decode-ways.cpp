class Solution {
public:
    unordered_map<int, int> memo;
    int numDecodings(string s) {
        return numDecodings(s, 0);
    }
private:
    int numDecodings(string& s, int idx) {
        if (memo.find(idx) != memo.end()) return memo[idx];
        if (s[idx] == '0') return 0;
        if (idx >= s.size() - 1) return 1;
        
        int res;
        res = numDecodings(s, idx + 1);
        if (stoi(s.substr(idx, 2)) <= 26) {
            res += numDecodings(s, idx + 2);
        }
        memo[idx] = res;
        return res;
    }
};