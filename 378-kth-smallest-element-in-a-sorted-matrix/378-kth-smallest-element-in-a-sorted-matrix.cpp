class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int start = matrix[0][0], end = matrix[n - 1][n - 1];
        int mid, smaller, larger, count;
        
        while (start < end) {
            mid = start + (end - start) / 2;
            smaller = matrix[0][0];
            larger = matrix[n - 1][n - 1];
            
            count = countLessEqual(matrix, mid, smaller, larger);
            
            // cout << "smaller is " << smaller << endl;
            // cout << "larger is " << larger << endl;
            
            if (k == count) return smaller;
            if (k > count) start = larger;
            else end = smaller;
        }
        return start;
    }
private:
    int countLessEqual(vector<vector<int>>& matrix, int& mid, int& smaller, int& larger) {
        int count = 0, n = matrix.size();
        int row = n - 1, col = 0;
        
        while (row >= 0 && col < n) {
            // right half of the array
            if (matrix[row][col] > mid) {
                larger = min(larger, matrix[row--][col]);
            }
            else {
                smaller = max(smaller, matrix[row][col++]);
                count += row + 1;
            }
        }
        return count;
    } 
};