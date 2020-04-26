#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int sq_length;

int find_square(int row_start, int col_start, const vvi &board);
int solution(vvi board);

int main() {
    vvi board = {{0,1,1,1},{1,1,1,1},{1,1,1,1},{0,0,1,0}};
    board = {{0,0,1,1},{1,1,1,1}};
    auto ans = solution(board);
    return 0;
}

int solution(vector<vector<int>> board)
{
    sq_length = 0;
    int row_size = board.size();
    int col_size = board[0].size();

    for (int row = 0; row < row_size; ++row) {
        for (int col = 0; col < col_size; ++col) {
            if (board[row][col] == 1) {
                int cur_max = find_square(row, col, board);
                sq_length = cur_max > sq_length ? cur_max : sq_length;
            }
        }
    }

    return sq_length * sq_length;
}

int find_square(int row_start, int col_start, const vvi &board) {
    int length = 1;
    int row_end = row_start + 1, col_end = col_start + 1;

    int poss_len_row = 0;
    for (int c_row = row_start; c_row < board.size(); ++c_row) {
        if (board[c_row][col_start] == 1) {
            poss_len_row++;
        } else {
            break;
        }
    }

    int poss_len_col = 0;
    for (int c_col = col_start; c_col < board[0].size(); ++c_col) {
        if (board[row_start][c_col] == 1) {
            poss_len_col++;
        } else {
            break;
        }
    }

    if (min(poss_len_col, poss_len_row) <= sq_length) return -1;

    int flag = true;
    while (row_end < board.size() && col_end < board[0].size()) {
        for (int c_row = row_start; c_row <= row_end; ++c_row) {
            if (board[c_row][col_end] == 0) {
                flag = false;
                break;
            }
        }

        if (!flag) break;

        for (int c_col = col_start; c_col <= col_end; ++c_col) {
            if (board[row_end][c_col] == 0) {
                flag = false;
                break;
            }
        }

        if (!flag) break;
        length++;
        row_end++, col_end++;
    }

    return length;
}