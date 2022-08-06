class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        
        for (char c: s) {
            if (stk.empty() || c != stk.top()) {
                stk.push(c);
            }
            else stk.pop();
        }
        
        string res = "";
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};