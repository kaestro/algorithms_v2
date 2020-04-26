#include <stdio.h>
#include <string.h>
#include <vector>

using vi = std::vector<int>;
using vvi = std::vector<vi>;

typedef struct {
    int widx;
    int row;
    int col;
} point;

vvi block;
point WormHole[10];

const int UP = 1, RIGHT = 2, DOWN = 3, LEFT = 4;

// left down
int Block_1(int dir) {
    int ans;
    switch (dir) {
        case UP: ans = DOWN; break;
        case RIGHT: ans = LEFT; break;
        case DOWN: ans = RIGHT; break;
        case LEFT: ans = UP; break;
    }
    return ans;
}

// left up
int Block_2(int dir) {
    int ans;
    switch (dir) {
        case UP: ans = RIGHT; break;
        case RIGHT: ans = LEFT; break;
        case DOWN: ans = UP; break;
        case LEFT: ans = DOWN; break;
    }
    return ans;
}

// right up
int Block_3(int dir) {
    int ans;
    switch (dir) {
        case UP: ans = LEFT; break;
        case RIGHT: ans = DOWN; break;
        case DOWN: ans = UP; break;
        case LEFT: ans = RIGHT; break;
    }
    return ans;
}

// right down
int Block_4(int dir) {
    int ans;
    switch (dir) {
        case UP: ans = DOWN; break;
        case RIGHT: ans = UP; break;
        case DOWN: ans = LEFT; break;
        case LEFT: ans = RIGHT; break;
    }
    return ans;
}

// SQUARE
int Block_5(int dir) {
    int ans;
    switch (dir) {
        case UP: ans = DOWN; break;
        case RIGHT: ans = LEFT; break;
        case DOWN: ans = UP; break;
        case LEFT: ans = RIGHT; break;
    }
    return ans;
}

int main() {
    int Test, count, ans;
    scanf("%d", &Test);

    for (int T = 1; T <= Test; ++T) {
        int Map_Size, WormHole_cnt = 0;
        count = 0;
        ans = -1;
        scanf("%d", &Map_Size);
        memset(WormHole, 0, sizeof(WormHole));
        block.resize(111, vi(111, 5));

        for (int row = 1; row <= Map_Size; ++row) {
            for (int col = 1; col <= Map_Size; ++col) {
                scanf("%d", &block[row][col]);

                if (block[row][col] >= 6) {
                    WormHole[WormHole_cnt].widx = block[row][col];
                    WormHole[WormHole_cnt].row = row;
                    WormHole[WormHole_cnt].col = col;
                    WormHole_cnt++;
                }
            }
        }

        for (int row = 1; row <= Map_Size; ++row) {
            for (int col = 1; col <= Map_Size; ++col) {
                if (block[row][col] != 0) continue;

                for (int i = 1; i <= 4; ++i) {
                    count = 0;
                    int dir = i, cur_row = row, cur_col = col;

                    while (true) {
                        switch (dir) {
                            case UP: cur_row--; break;
                            case RIGHT: cur_col++; break;
                            case DOWN: cur_row++; break;
                            case LEFT: cur_col--; break;
                        }

                        int block_val = block[cur_row][cur_col];
                        if ((cur_row == row && cur_col == col) || block[cur_row][cur_col] == -1) {
                            break;
                        } else if (block_val >= 1 && block_val <= 5) {
                            switch (block_val) {
                                case 1: dir = Block_1(dir); break;
                                case 2: dir = Block_2(dir); break;
                                case 3: dir = Block_3(dir); break;
                                case 4: dir = Block_4(dir); break;
                                case 5: dir = Block_5(dir); break;
                            }
                            count++;
                        } else if (block_val >= 6) {
                            for (int W = 0; W < WormHole_cnt; ++W) {
                                if (WormHole[W].widx == block_val && (WormHole[W].row != cur_row || WormHole[W].col != cur_col)) {
                                    cur_row = WormHole[W].row;
                                    cur_col = WormHole[W].col;
                                    break;
                                }
                            }
                        }
                    }
                    if (count > ans)
                        ans = count;
                }
            }
        }
        printf("%d %d\n", T, ans);
    }
    return 0;
}