#include <vector>
#include <queue>

using namespace std;

using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

class Solution {
private:
    void bfs(vvc &grid, int row, int col) {
        queue<vi> gridq;
        gridq.push({row, col});
        grid[row][col] = '0';
        while (!gridq.empty()) {
            auto cur_grid = gridq.front(); gridq.pop();
            int cur_row = cur_grid[0], cur_col = cur_grid[1];

            for (int i = 0; i < 4; ++i) {
                int nr = cur_row + dr[i];
                int nc = cur_col + dc[i];
                if (nr >= 0 && nr < row_end && nc >= 0 && nc < col_end) {
                    if (grid[nr][nc] == '1') {
                        grid[nr][nc] = '0';
                        gridq.push({nr, nc});
                    }
                }
            }
        }
    }

    int row_end, col_end;
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        row_end = grid.size(), col_end = grid[0].size();

        for (int row = 0; row < row_end; ++row) {
            for (int col = 0; col < col_end; ++col) {
                if (grid[row][col] == '1') {
                    ans++;
                    bfs(grid, row, col);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vvc grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    auto ans = s.numIslands(grid);
    return 0;
}