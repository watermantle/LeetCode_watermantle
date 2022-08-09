class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int res = -1;
        double dis_min = DBL_MAX;
        for (int i = 0; i < points.size(); ++i) {
            vector<int> point = points[i];
            double dis = DBL_MAX;
            if (point[0] == x) dis = abs(point[1] - y);
            else if (point[1] == y) dis = abs(point[0] - x);
            if (dis_min > dis) {
                res = i;
                dis_min = dis;
            }
        }
        return dis_min == DBL_MAX ? -1 : res;
    }
};