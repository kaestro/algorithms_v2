#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Wormhole {
public:
    Wormhole(int r, int c, int w)
        :row(r), col(c), w_idx(w) {}
    int w_idx, row, col;
};

const int UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;
const int T_DL = 1, T_UL = 2, T_UR = 3, T_DR = 4, SQ = 5;
const int Empty = 0, BlackHole = -1;
const int board_limit = 102;


vector<Wormhole> worm_holes;
int board[board_limit][board_limit];

int ans;
int board_size;

void reset();
void init();
void solution();
void move(int &row, int &col, int &dir);

void block_TDL(int &dir);
void block_TUL(int &dir);
void block_TDR(int &dir);
void block_TUR(int &dir);
void block_SQ(int &dir);

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        reset();
        init();
        solution();
        cout << "#" << test_case << " " << ans << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void reset() {
    worm_holes.clear();
    ans = 0;
    for (int row = 0; row < board_limit; ++row) {
        for (int col = 0; col < board_limit; ++col) {
            board[row][col] = SQ;
        }
    }
}

void init() {
    cin >> board_size;
    for (int row = 1; row <= board_size; ++row) {
        for (int col = 1; col <= board_size; ++col) {
            cin >> board[row][col];
            if (board[row][col] > 5) {
                worm_holes.push_back(Wormhole(row, col, board[row][col]));
            }
        }
    }
}

void solution() {
    for (int row = 1; row <= board_size; ++row) {
        for (int col = 1; col <= board_size; ++col) {
            if (board[row][col] != Empty) continue;
            board[row][col] = BlackHole;

            for (int i = 0; i < 4; ++i) {
                int c_row = row, c_col = col, dir = i;
                int res = 0;

                while (true) {
                    move(c_row, c_col, dir);

                    int board_val = board[c_row][c_col];
                    if (board_val == BlackHole) {
                        ans = max(res, ans);
                        break;
                    } else if (board_val > 0 && board_val <= SQ) {
                        switch (board_val) {
                            case T_DL: block_TDL(dir); break;
                            case T_UL: block_TUL(dir); break;
                            case T_DR: block_TDR(dir); break;
                            case T_UR: block_TUR(dir); break;
                            case SQ: block_SQ(dir); break;
                        }
                        res++;
                    } else if (board_val != Empty) {
                        for (const auto &wh : worm_holes) {
                            if (wh.w_idx == board_val && (wh.row != c_row || wh.col != c_col)) {
                                c_row = wh.row;
                                c_col = wh.col;
                                break;
                            }
                        }
                    }
                }
            }
            board[row][col] = Empty;
        }
    }
}

void move(int &row, int &col, int &dir) {
    switch (dir) {
        case UP: row--; break;
        case DOWN: row++; break;
        case LEFT: col--; break;
        case RIGHT: col++; break;
    }
}

void block_TDL(int &dir) {
    switch (dir) {
        case UP: dir = DOWN; break;
        case RIGHT: dir = LEFT; break;
        case DOWN: dir = RIGHT; break;
        case LEFT: dir = UP; break;
    }
}

void block_TUL(int &dir) {
    switch (dir) {
        case UP: dir = RIGHT; break;
        case RIGHT: dir = LEFT; break;
        case DOWN: dir = UP; break;
        case LEFT: dir = DOWN; break;
    }
}

void block_TDR(int &dir) {
    switch (dir) {
        case UP: dir = DOWN; break;
        case RIGHT: dir = UP; break;
        case DOWN: dir = LEFT; break;
        case LEFT: dir = RIGHT; break;
    }
}

void block_TUR(int &dir) {
    switch (dir) {
        case UP: dir = LEFT; break;
        case RIGHT: dir = DOWN; break;
        case DOWN: dir = UP; break;
        case LEFT: dir = RIGHT; break;
    }
}

void block_SQ(int &dir) {
    switch (dir) {
        case UP: dir = DOWN; break;
        case RIGHT: dir = LEFT; break;
        case DOWN: dir = UP; break;
        case LEFT: dir = RIGHT; break;
    }
}