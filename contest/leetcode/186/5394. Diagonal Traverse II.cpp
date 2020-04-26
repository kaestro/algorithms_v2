#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& board) {
        vi ans;
        int row_start = 0, col_start = 0;
        int row_end = board.size(), col_end = 0;
        for (auto &row : board) col_end = max(col_end, (int)row.size());

        while (col_start < col_end) {
            int row = row_start;
            int col = col_start;

            while (row >= 0 && col < col_end) {
                if (col < board[row].size()) ans.push_back(board[row][col]);
                row--, col++;
            }

            if (row_start == row_end - 1) col_start++;
            else row_start++;
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    nums = {{1,2,3,4,5},{6,7},{8},{9,10,11},{12,13,14,15,16}};
    Solution s;
    auto ans = s.findDiagonalOrder(nums);

    return 0;
}