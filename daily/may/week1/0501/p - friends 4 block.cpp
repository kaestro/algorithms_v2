#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> input) {
    int answer = 0;
    vector<string> board(n, string(m, ' '));
    for (int row = 0; row < m; ++row) {
        for (int col = 0; col < n; ++col) {
            board[col][row] = input[row][col];
        }
    }

    while (true) {
        int cnt = 0;
        for (int row = 0; row < n - 1; ++row) {
            for (int col = 0; col < m - 1; ++col) {
                char &val = board[row][col];
                if (val == ' ') continue;
                if (val == board[row][col+1] && val == board[row+1][col] && val == board[row+1][col+1]) 
                    val = 'x';
            }
        }

        for (int row = 0; row < n - 1; ++row) {
            for (int col = 0; col < m - 1; ++col) {
                char &val = board[row][col];
                if (val == 'x') {
                    for (int i = 0; i <= 1; ++i) {
                        for (int j = 0; j <= 1; ++j) {
                            char &grid = board[row + i][col + j];
                            if (grid != 'x' && grid != ' ') {
                                grid = ' ';
                                cnt++;
                            }
                        }
                    }
                    val = ' ';
                    cnt++;
                }
            }
        }

        for (int row = 0; row < n; ++row) {
            int y_cnt = 0;
            auto it = board[row].begin();
            while (it != board[row].end()) {
                if (*it == ' ') {
                    y_cnt++;
                    it = board[row].erase(it);
                } else {
                    it++;
                }
            }
            board[row].insert(0, string(y_cnt, ' '));
        }

        if (cnt == 0) break;
        else answer += cnt;
    }
    return answer;
}

int main() {
    int m = 4, n = 5;
    vector<string> board = {"CCBDE", "AAADE", "AAABF", "CCBBF"};
    auto ans = solution(m, n, board);
    return 0;
}