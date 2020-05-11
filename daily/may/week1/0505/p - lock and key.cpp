// 자물쇠와 열쇠
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int filled_holes(vvi key, vvi board, int row_beg, int col_beg) {
    int key_size = key.size();
    int cnt = 0;
    for (int row = 0; row < key_size; ++row) {
        for (int col = 0; col < key_size; ++col) {
            int board_val = board[row_beg + row][col_beg + col];
            int key_val = key[row][col];
            if (board_val == 0 && key_val == 1) cnt += 1;
            else if (board_val == 1 && key_val == 1) return -1;
        }
    }
    return cnt;
}

vector<vvi> generate_keys(vvi &key) {
    vector<vvi> ans;
    ans.push_back(key);
    int key_size = key.size();
    for (int i = 0; i < 3; ++i) {
        for (int row = 0; row < key_size / 2; row++) { 
            for (int col = row; col < key_size - row - 1; col++) { 
    
                // Swap elements of each cycle 
                // in clockwise direction 
                int temp = key[row][col]; 
                key[row][col] = key[key_size - 1 - col][row]; 
                key[key_size - 1 - col][row] = key[key_size - 1 - row][key_size - 1 - col]; 
                key[key_size - 1 - row][key_size - 1 - col] = key[col][key_size - 1 - row]; 
                key[col][key_size - 1 - row] = temp; 
            } 
        }
        ans.push_back(key);
    }
    return ans;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int key_size = key.size(), lock_size = lock.size();
    int board_size = 2 * key_size + lock_size - 2;
    int holes = 0;

    for (auto row : lock) {
        for (auto val : row) {
            holes += (1 - val);
        }
    }

    vvi board(board_size, vi(board_size, -1));
    for (int row = 0; row < lock_size; ++row) {
        for (int col = 0; col < lock_size; ++col) {
            int board_row = row + key_size - 1;
            int board_col = col + key_size - 1;
            board[board_row][board_col] = lock[row][col];
        }
    }

    vector<vvi> keys = generate_keys(key);

    for (auto n_key : keys) {
        for (int row = 0; row <= key_size + lock_size - 2; ++row) {
            for (int col = 0; col <= key_size + lock_size - 2; ++col) {
                if(holes == filled_holes(n_key, board, row, col))
                    return true;
            }
        }
    }

    return false;
}

int main(){
    vvi key = {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}};
    vvi lock = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    auto ans = solution(key, lock);
    return 0;
}