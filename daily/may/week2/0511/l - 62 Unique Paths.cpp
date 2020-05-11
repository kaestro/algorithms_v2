#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> board(m, vector<int>(n, 1));

        for (int row = 1; row < m; ++row) {
            for (int col = 1; col < n; ++col) {
                board[row][col] = board[row - 1][col] + board[row][col - 1];
            }
        }

        return board[m - 1][n - 1];
    }
};