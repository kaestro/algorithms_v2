#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

typedef struct _Point{
    int row, col;

    _Point(int r, int c) : row(r), col(c){};
} Point;

const int board_limit = 100;
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};
const int WORMHOLE_OFFSET = 5;
const int LEFTDOWN = 1, LEFTUP = 2, RIGHTUP = 3, RIGHTDOWN = 4, SQUARE = 5;

const int UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;
const int BLACK_HOLE = -1;

int board[board_limit][board_limit];
vector<Point> worm_holes[5];
int board_size; 
int ans;
int cur_score;

void reset();
void init();
void solution();
void bfs(Point start, int dir_idx);
void move(Point &cur_point, int &dir_idx);
void reverse_dir(int &dir_idx);

bool met_wall(int row, int col, int dir_idx);
bool met_slope(int row, int col, int &dir_idx);

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
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void reset() {
    memset(board, 0, sizeof(board));
    for (int i = 0; i < 5; ++i)
        worm_holes[i].clear();
    board_size = 0, ans = 0;
}

void init() {
    cin >> board_size;
    for (int row = 0; row < board_size; ++row) {
        for (int col = 0; col < board_size; ++col) {
            cin >> board[row][col];

            if (board[row][col] > WORMHOLE_OFFSET) {
                worm_holes[board[row][col] - WORMHOLE_OFFSET].push_back(Point(row, col));
            }
        }
    }
}

void solution() {
    for (int row = 0; row < board_size; ++row) {
        for (int col = 0; col < board_size; ++col) {
            if (board[row][col] == 0) {
                board[row][col] = -1;
                for (int i = 0; i < 4; ++i) {
                    bfs(Point(row, col), i);
                }
                board[row][col] = 0;
            }
        }
    }
}

void bfs(Point start, int dir_idx) {
    Point cur(start.row, start.col);
    cur_score = 0;
    while (true) {
        move(cur, dir_idx);
        if (board[cur.row][cur.col] == -1)
            break;
    }
    ans = ans >= cur_score ? ans : cur_score;
}

void move(Point &cur, int &dir_idx) {
    int nr = cur.row + dr[dir_idx];
    int nc = cur.col + dc[dir_idx];

    int val = board[nr][nc];
    if (met_wall(nr, nc, dir_idx)) {
        cur_score++;
        reverse_dir(dir_idx);
        cur.row += dr[dir_idx];
        cur.col += dc[dir_idx];
    } else if (met_slope(nr, nc, dir_idx)){ // met slope
        cur.row = nr;
        cur.col = nc;
    } else if (val > WORMHOLE_OFFSET) {

    } else {
        cur.row = nr;
        cur.col = nc;
    }
}

void reverse_dir(int &dir_idx) {
    switch(dir_idx) {
        case UP: dir_idx = DOWN; break;
        case DOWN: dir_idx = UP; break;
        case LEFT: dir_idx = RIGHT; break;
        case RIGHT: dir_idx = LEFT; break;
    }
}

bool met_wall(int row, int col, int dir) {
    if (row < 0 || row >= board_size || col < 0 || col >= board_size) return true;

    int block = board[row][col];
    if (block == SQUARE) return true;

    if (dir == UP && (block == LEFTDOWN || block == RIGHTDOWN)) return true;
    if (dir == DOWN && (block == LEFTUP || block == RIGHTUP)) return true;
    if (dir == LEFT && (block == LEFTDOWN || block == LEFTUP)) return true;
    if (dir == RIGHT && (block == RIGHTDOWN || block == RIGHTUP)) return true;
}

bool met_slope(int row, int col, int &dir) {
    int block = board[row][col];
    bool flag = true;

    if (dir == UP && block == LEFTUP) dir = RIGHT;
    else if (dir == UP && block == RIGHTUP) dir = LEFT;
    else if (dir == DOWN && block == LEFTDOWN) dir = RIGHT;
    else if (dir == DOWN && block == RIGHTDOWN) dir = LEFT;
    else if (dir == LEFT && block == LEFTUP) dir = DOWN;
    else if (dir == LEFT && block == LEFTDOWN) dir = UP;
    else if (dir == RIGHT && block == RIGHTUP) dir = DOWN;
    else if (dir == RIGHT && block == RIGHTDOWN) dir = UP;
    else flag = false;

    return flag;
}