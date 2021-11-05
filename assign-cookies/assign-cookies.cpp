class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.empty()) return 0;
        
        int res = 0;
        int idx = s.size() - 1;
        
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        
        for (int i = g.size() - 1; i >=0; i--){
            if (idx >= 0 && s[idx] >= g[i]){
                res++; idx--;
            }
        }
        return res;
    }
};
