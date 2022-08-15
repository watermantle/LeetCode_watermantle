class Solution {
public:
    string toLowerCase(string s) {
        stringstream ss;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] <= 'Z' && s[i] >= 'A') {
                char c = s[i] - 'A' + 'a';
                ss << c;
            }
            else ss << s[i];
        }
        return ss.str();
    }
};