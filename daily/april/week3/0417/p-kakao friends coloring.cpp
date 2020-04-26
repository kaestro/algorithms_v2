#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int max_row, max_col;

int bfs(vvi &picture, int row, int col, int val){
    int res = 1;
    queue<vi> bq;
    bq.push({row,col});
    picture[row][col] = 0;
    while (!bq.empty()) {
        auto grid = bq.front(); bq.pop();
        int cur_row = grid[0], cur_col = grid[1];
        for (int i = 0; i < 4; ++i) {
            int nr = cur_row + dr[i], nc = cur_col + dc[i];
            if (nr >= 0 && nr < max_row && nc >= 0 && nc < max_col) {
                if (picture[nr][nc] == val) {
                    picture[nr][nc] = 0;
                    res++;
                    bq.push({nr, nc});
                }
            }
        }
    }
    return res;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size = 0;
    max_row = m, max_col = n;
    
    vector<int> answer(2);
    for (int row = 0; row < m; ++row) {
        for (int col = 0; col < n; ++col) {
            if (picture[row][col] != 0) {
                int cur_size = bfs(picture, row, col, picture[row][col]);
                number_of_area++;
                max_size = max(cur_size, max_size);
            }
        }
    }
    answer[0] = number_of_area;
    answer[1] = max_size;
    return answer;
}