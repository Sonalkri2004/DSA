// Complexy: Time O(m * n) & Space O(m * n)

// class Solution {
// public:
//     vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
//         int ROWS = box.size();
//         int COLS = box[0].size();
        
//         vector<vector<char>> res(COLS, vector<char>(ROWS, '.'));
        
//         for (int r = 0; r < ROWS; r++) {
//             int i = COLS - 1;
//             for (int c = COLS - 1; c >= 0; c--) {
//                 if (box[r][c] == '#') {
//                     res[i][ROWS - r - 1] = '#';
//                     i--;
//                 }
//                 else if (box[r][c] == '*') {
//                     res[c][ROWS - r - 1] = '*';
//                     i = c - 1;
//                 }
//             }
//         }
        
//         return res;
//     }
// };

// solution 2

// Complexy: Time O(m * n) & Space O(m * n)


class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        
        for (auto& row : box) {
            int dropPos = n - 1;
            
            for (int currPos = n - 1; currPos >= 0; currPos--) {
                if (row[currPos] == '*') {
                    dropPos = currPos - 1;
                }
                else if (row[currPos] == '#') {
                    swap(row[dropPos], row[currPos]);
                    dropPos--;
                }
            }
        }
        
        vector<vector<char>> rotatedBox(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rotatedBox[j][m - 1 - i] = box[i][j];
            }
        }
        
        return rotatedBox;
    }
};