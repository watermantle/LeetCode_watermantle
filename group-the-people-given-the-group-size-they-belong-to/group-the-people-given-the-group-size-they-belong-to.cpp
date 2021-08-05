class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> gp;
        vector<vector<int>> res;
        
        // make a map with #of people as key and idx as values
        for (int i = 0; i != groupSizes.size(); i++){
            gp[groupSizes[i]].push_back(i);
        }
        
        for (auto it : gp){
            int idx = 0;
            int key = it.first;
            vector<int> val = it.second;
            
            // separate a vector into pcs if the vector is too long
            int t = floor(val.size() / key);
            for (int i = 0; i != t; i++){
                vector<int> v = vector<int>(val.begin() + idx, val.begin() + idx + key);
                res.push_back(v);
                idx += key;
            }
        }
    return res;
    }
};