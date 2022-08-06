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
        
        stringstream ss;
        while (!stk.empty()) {
            ss << stk.top();
            cout << stk.top() << endl;
            stk.pop();
        }
        string res = ss.str();
        reverse(res.begin(), res.end());
        return res;
    }
};