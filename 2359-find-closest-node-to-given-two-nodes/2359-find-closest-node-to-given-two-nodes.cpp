class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int res = -1, dis_min = INT_MAX;
        vector<int> memo1(edges.size(), -1), memo2(edges.size(), -1);
        dfs(node1, 0, edges, memo1);
        dfs(node2, 0, edges, memo2);
        
        for (int i = 0; i < edges.size(); ++i) {
            if(min(memo1[i], memo2[i]) >= 0 && max(memo1[i], memo2[i]) < dis_min) {
                dis_min = max(memo1[i], memo2[i]);
                res = i;
            }
        }
        return res;
    }
private:
    void dfs(int node, int dis, vector<int>& edges, vector<int>& memo) {
        while (node != -1 && memo[node] == -1) {
            memo[node] = dis++;
            node = edges[node];
        }
    }
};