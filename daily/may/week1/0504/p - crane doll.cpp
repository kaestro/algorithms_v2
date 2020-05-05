#include <string>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> stk;
    vector<vector<int>> flip_board(board[0].size());
    for (int row = board.size() - 1; row >= 0; --row) {
        for (int col = board[0].size() - 1; col >= 0; --col) {
            if (board[row][col] != 0) {
                flip_board[col].push_back(board[row][col]);
            }
        }
    }

    for (auto move : moves) {
        move -= 1;
        if (flip_board[move].empty()) continue;
        auto doll = flip_board[move].back();
        if (!stk.empty() && stk.back() == doll) {
            stk.pop_back();
            answer += 2;
        } else {
            stk.push_back(doll);
        }
        flip_board[move].pop_back();
    }
    return answer;
}

int main() {
    vvi board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vi moves = {1,5,3,5,1,2,1,4};
    auto ans =solution(board, moves);

    return 0;
}