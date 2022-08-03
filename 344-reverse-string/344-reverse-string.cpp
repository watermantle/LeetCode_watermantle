class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> stk;
        for (char& c: s) stk.push(c);
        vector<char> s_r;
        while (!stk.empty()) {
            char c = stk.top(); stk.pop();
            s_r.push_back(c);
        }
        s = s_r;
    }
};