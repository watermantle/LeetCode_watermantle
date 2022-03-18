class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int memo[256] = {0}; // to store all chars, starting with 0
        int left = 0, right = 0;
        int res = 0;
        
        while (right < s.length()){
            memo[s[right]]++; // increase the current char
            while (memo[s[right]] > 1){
                memo[s[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};