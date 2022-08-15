class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> map;
        map["M"] = 1000;
        map["D"] = 500;
        map["C"] = 100;
        map["L"] = 50;
        map["X"] = 10;
        map["V"] = 5;
        map["I"] = 1;
        
        int sum = 0;
        int i = 0;
        while (i < s.size()) {
            string currSymbol = s.substr(i, 1);
            int currVal = map[currSymbol];
            int nextVal = 0;
            if (i + 1 < s.size()) {
                string nextSymbol = s.substr(i + 1, 1);
                nextVal = map[nextSymbol];
            }
            if (currVal < nextVal) {
                sum += (nextVal - currVal);
                i += 2;
            }
            else {
                sum += currVal;
                i += 1;
            }
        }
        return sum;
    }
};