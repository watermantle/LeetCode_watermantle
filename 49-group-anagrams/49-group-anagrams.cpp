class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        
        for (string& str: strs) {
            mp[convert(str)].push_back(str);
        }
        for (auto& item: mp) {
            res.push_back(item.second);
        }
        return res;
    }
private:
    string convert(string& str) {
        vector<int> temp(26, 0);
        for (char& c: str) temp[c - 'a']++;
        
        stringstream ss;
        for (int& i: temp) ss << "," << i;
        cout << ss.str() << endl;
        return ss.str();
    }
};