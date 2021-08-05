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
            // separate a vector into pcs if the vector is too long
            int t = floor(it.second.size() / it.first);
            for (int i = 0; i != t; i++){
                vector<int> v = vector<int>(it.second.begin() + idx, it.second.begin() + idx + it.first);
                res.push_back(v);
                idx += it.first;
            }
        }
    return res;
    }
};