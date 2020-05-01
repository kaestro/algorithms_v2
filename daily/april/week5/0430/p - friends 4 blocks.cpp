#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> input) {
    int answer = 0;
    int width = input[0].length();
    int height = input.size();
    vector<string> board(width, string(height, ' '));
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            board[col][row] = input[row][col];
        }
    }

    while (true) {
        int cnt = 0;

        for (int row = 0; row < width - 1; ++row) {
            for (int col = 0; col < height - 1; ++col) {
                if (board[row][col] == 'y') continue;
                if (board[row][col] == board[row][col + 1] &&
                    board[row][col] == board[row + 1][col] &&
                    board[row][col] == board[row + 1][col + 1]
                ) {
                    board[row][col] = 'x';
                }
            }
        }

        for (int row = 0; row < width - 1; ++row) {
            for (int col = 0; col < height - 1; ++col) {
                if (board[row][col] == 'x') {
                    if (board[row][col + 1] != 'x' && board[row][col + 1] != 'y') {
                        board[row][col + 1] = 'y';
                        cnt++;
                    }
                    if (board[row + 1][col] != 'x' && board[row + 1][col] != 'y') {
                        board[row + 1][col] = 'y';
                        cnt++;
                    }
                    if (board[row + 1][col + 1] != 'x' && board[row + 1][col + 1] != 'y') {
                        board[row + 1][col + 1] = 'y';
                        cnt++;
                    }
                    board[row][col] = 'y';
                    cnt++;
                }
            }
        }

        if (cnt == 0) break;
        else {
            for (int row = 0; row < width; ++row) {
                int y_cnt = 0;
                auto &str = board[row];
                auto it = str.begin();
                while (it != str.end()) {
                    if (*it == 'y') {
                        it = str.erase(it);
                        y_cnt++;
                    } else {
                        it++;
                    }
                }
                str.insert(0, string(y_cnt, 'y'));
            }
            answer += cnt;
        }
    }
    return answer;
}

int main() {
    vector<string> board = {
        "TTTANT",
        "RRFACC",
        "RRRFCC",
        "TRRRAA",
        "TTMMMF",
        "TMMTTJ"
    };
    auto ans = solution(4, 5, board);
    board = {"CCBDE", "AAADE", "AAABF", "CCBBF"};
    ans = solution(4, 5, board);
    return 0;
}