class Solution {
public:
    unordered_map<string, int> wordCount;
    int wordLen;
    int substrLen;
    int k;
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        k = words.size();
        wordLen = words[0].size();
        substrLen = wordLen * k;
        
        unordered_map<string, int> wordCount;
        for (string& word: words) wordCount[word]++;
        
        vector<int> res;
        
        for (int i = 0; i < n - substrLen + 1; ++i) {
            if (check(i, s, wordCount)) res.push_back(i);
        }
        return res;
    }
    
    bool check(int i, string& s, unordered_map<string, int> remain) {
        int wordUsed = 0;
        
        for (int j = i; j < i + substrLen; j += wordLen) {
            string sub = s.substr(j, wordLen);
            if (remain[sub] > 0) {
                remain[sub]--;
                wordUsed++;
            } else break;
        }
        return wordUsed == k;
    }
};