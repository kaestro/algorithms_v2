#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
    int ans = 0;
    for (int row = 0; row < board.size(); ++row) {
        if (board[row][0]) {
            ans = 1;
            break;
        }
    }
    
    if (ans == 0) {
        for (int col = 0; col < board[0].size(); ++col) {
            if (board[0][col]) {
                ans = 1;
                break;
            }
        }
    }
    
    for (int row = 1; row < board.size(); ++row) {
        for (int col = 1; col < board[0].size(); ++col) {
            if (board[row][col]) {
                board[row][col] = min(min(board[row - 1][col - 1], board[row][col - 1]), board[row - 1][col]) + 1;
                ans = max(ans, board[row][col]);
            }
        }
    }

    return ans * ans;
}

int main() {
    vector<vector<int>> board = {{0,0,1,1},{1,1,1,1}};
    auto ans = solution(board);
    return 0;
}