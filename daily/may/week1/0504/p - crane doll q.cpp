#include <string>
#include <vector>
#include <queue>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int solution(vector<vector<int>> input_board, vector<int> moves) {
    int answer = 0;
    vector<queue<int>> board(input_board[0].size());
    vector<int> stk;
    for (int row = 0; row < input_board.size(); ++row) {
        for (int col = 0; col < input_board[0].size(); ++col) {
            if (input_board[row][col] == 0) continue;
            board[col].push(input_board[row][col]);
        }
    }

    for (auto move : moves) {
        move--;
        if (board[move].empty()) continue;
        auto doll = board[move].front();
        if (!stk.empty() && stk.back() == doll) {
            stk.pop_back();
            answer += 2;
        } else {
            stk.push_back(doll);
        }
        board[move].pop();
    }
    return answer;
}

int main() {
    vvi board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vi moves = {1,5,3,5,1,2,1,4};
    auto ans =solution(board, moves);

    return 0;
}