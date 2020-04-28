#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Wormhole {
public:
    Wormhole(int r, int c, int w)
        :row(r), col(c), w_idx(w) {}
    int row, col;
    int w_idx;
};

const int board_limit = 102;
const int UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3;

int board[board_limit][board_limit];
int board_size;
int ans;

vector<Wormhole> worm_holes;

void reset();
void init();
void solution();
void move(int &row, int &col, int &dir);
void block1(int &dir); //leftdown
void block2(int &dir); //leftup
void block3(int &dir); //right up
void block4(int &dir); //rightdown
void block5(int &dir); //square


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
	return 0;
}

void reset() {
    board_size = 0, ans = 0;
    worm_holes.clear();
    for (int row = 0; row < board_limit; ++row) {
        for (int col = 0; col < board_limit; ++col) {
            board[row][col] = 5;
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
            if (board[row][col] != 0) continue;
            board[row][col] = -1;

            for (int i = 0; i < 4; ++i) {
                int score = 0;
                int dir = i;
                int c_row = row, c_col = col;

                while (true) {
                    move(c_row, c_col, dir);

                    int grid = board[c_row][c_col];
                    if (grid == -1) {
                        ans = max(ans, score);
                        break;
                    } else if (grid >= 1 && grid <= 5) {
                        switch (grid) {
                            case 1: block1(dir); break;
                            case 2: block2(dir); break;
                            case 3: block3(dir); break;
                            case 4: block4(dir); break;
                            case 5: block5(dir); break;
                        }
                        score++;
                    } else if (grid != 0){
                        for (const auto &wh : worm_holes) {
                            if (wh.w_idx == grid && (wh.row != c_row || wh.col != c_col)) {
                                c_row = wh.row;
                                c_col = wh.col;
                                break;
                            }
                        }
                    }
                }
            }

            board[row][col] = 0;
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

//leftdown
void block1(int &dir){
    switch (dir) {
        case UP: dir = DOWN; break;
        case DOWN: dir = RIGHT; break;
        case LEFT: dir = UP; break;
        case RIGHT: dir = LEFT; break;
    }
}

//left up
void block2(int &dir) {
    switch (dir) {
        case UP: dir = RIGHT; break;
        case DOWN: dir = UP; break;
        case LEFT: dir = DOWN; break;
        case RIGHT: dir = LEFT; break;
    }
}

//right up
void block3(int &dir) {
    switch (dir) {
        case UP: dir = LEFT; break;
        case DOWN: dir = UP; break;
        case LEFT: dir = RIGHT; break;
        case RIGHT: dir = DOWN; break;
    }
} 

//right down
void block4(int &dir) {
    switch (dir) {
        case UP: dir = DOWN; break;
        case DOWN: dir = LEFT; break;
        case LEFT: dir = RIGHT; break;
        case RIGHT: dir = UP; break;
    }
} 

//square
void block5(int &dir) {
    switch (dir) {
        case UP: dir = DOWN; break;
        case DOWN: dir = UP; break;
        case LEFT: dir = RIGHT; break;
        case RIGHT:  dir = LEFT; break;
    }
} 