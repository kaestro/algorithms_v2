#include <vector>
#include <algorithm>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row_size = grid.size();
        if (row_size == 0) return 0;
        int col_size = grid[0].size();
        for (int col = 1; col < col_size; ++col)
            grid[0][col] += grid[0][col - 1];
        
        for (int row = 1; row < row_size; ++row)
            grid[row][0] += grid[row - 1][0];
        
        for (int row = 1; row < row_size; ++row) {
            for (int col = 1; col < col_size; ++col) {
                grid[row][col] += min(grid[row - 1][col], grid[row][col - 1]);
            }
        }

        return grid[row_size - 1][col_size - 1];
    }
};