class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size();
        int mid;
        
        while (left < right) {
            mid = left + (right - left) / 2;
            if (letters[mid] > target) right = mid;
            else if (letters[mid] <= target) left = mid + 1;
        }
        return letters[left % letters.size()];
    }
};