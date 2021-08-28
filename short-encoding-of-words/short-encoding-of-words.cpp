class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> words_set;
        
        for (int i = 0; i < words.size(); ++i ){
            words_set.insert(words[i]);
        }
        
        for (string word : words){
            for (int k = 1; k < word.size(); ++k){
                words_set.erase(word.substr(k));
            }
        }
        
        int res = 0;
        for (string word: words_set){
            res += word.length() + 1;
        }
        return res;
    }
};