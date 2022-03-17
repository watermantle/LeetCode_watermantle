class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string curr = "";
        int res = 0;
        for (auto c: s){
            if (!count(curr.begin(), curr.end(), c)) curr = curr + c;
            else{
                int idx = curr.find(c);
                curr = curr.substr(idx + 1) + c;
            }
            res = res > curr.length() ? res: curr.length();
        }
        return res;
    }
};