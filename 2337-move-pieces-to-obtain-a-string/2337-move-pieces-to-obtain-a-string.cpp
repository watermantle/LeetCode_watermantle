class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();
        int i = 0, j = 0;
        
        while (i < n || j < n) {
            while (start[j] == '_') ++j;
            while (target[i] == '_') ++i;
            
            if (i == n || j == n) return i == n && j == n;
            if (start[j] != target[i]) return false;
            
            if (target[i] == 'L') {
                if (i > j) return false;
            }
            else{
                if (i < j) return false;
            }
            ++i;
            ++j;
        }
        return true;
    }
};