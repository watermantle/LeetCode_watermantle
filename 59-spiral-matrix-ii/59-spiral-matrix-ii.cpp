class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int> (n, 0));
        int sx = 0, sy = 0; // start point for every loop
        int n_loop = n / 2;
        int mid = n / 2;
        int num = 1;
        int offset = 1;
        int i, j;
        
        while (n_loop--) {
            i = sx;
            j = sy;
            
            for (j = sy; j < n - offset; ++j) res[sx][j] = num++;
            for (i = sx; i < n - offset; ++i) res[i][j] = num++;
            
            for(; j > sy; --j) res[i][j] = num++;
            for(; i > sx; --i) res[i][j] = num++;
            
            sx++;
            sy++;
            offset++;
        }
        
        if (n % 2) res[mid][mid] = num;
        
        return res;
    }
};