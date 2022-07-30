class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>  mg(26, 0);
        for (char& c: magazine) mg[c - 'a']++;
        for (char& c: ransomNote) mg[c - 'a']--;
        
        for (int& feq: mg) {
            if (feq < 0) return false;
        }
        return true;
    }
};