class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int idx1 = 0, idx2 = 0;
        stringstream ss;
        while (idx1 < word1.size() && idx2 < word2.size()) {
            ss << word1[idx1++];
            ss << word2[idx2++];
        }
        
        while (idx1 < word1.size()) ss << word1[idx1++];
        while (idx2 < word2.size()) ss << word2[idx2++];
        return ss.str();
    }
};