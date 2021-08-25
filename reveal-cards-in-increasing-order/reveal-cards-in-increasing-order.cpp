class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        vector<int> res(n);

        queue<int> idx_q;
        for (int i = 0; i != n; i++) {
            idx_q.push(i);
        }

        int j = 0;
        while (!idx_q.empty()) {
            // store card with order in idx_q
            res[idx_q.front()] = deck[j];  idx_q.pop();

            // put the second top card to the end
            if (!idx_q.empty()) {
                int top_sed = idx_q.front(); idx_q.pop();
                idx_q.push(top_sed);
                j++;
            }
        }
        
        return res;
    }
};