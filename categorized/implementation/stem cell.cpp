// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRJ8EKe48DFAUo
// 5653. [모의 SW 역량테스트] 줄기세포배양
// date: 10.03.2020
// purpose: review

#include <iostream>

using namespace std;

const int MAXL = 352;

enum status {
    EMPTY,
    INACTIVE,
    ACTIVE,
    DEAD
};

class Cell {
public:
    Cell() :cellStat(EMPTY), lp(0), hp(0)
        {}

    void reset() {
        cellStat = EMPTY;
        lp = 0, hp = 0;
    }

    status cellStat;
    int lp, hp;
};

int T, N, M, K, OFFSET;
Cell Map[2][MAXL][MAXL];
const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main() {
    cin >> T;

    for (int tc = 1; tc <= T; ++tc) {
        cin >> N >> M >> K;

        OFFSET = K / 2 + 1;

        for(int row = 0; row < N + K + 2; ++row) {
            for (int col = 0; col < M + K + 2; ++col) {
                Map[0][row][col].reset();
                Map[1][row][col].reset();
            }
        }

        for (int row = OFFSET; row < N + OFFSET; ++row) {
            for (int col = OFFSET; col < M + OFFSET; ++col) {
                Cell& curCell = Map[0][row][col];
                cin >> curCell.lp;
                if (curCell.lp > 0) {
                    curCell.cellStat = INACTIVE;
                }
            }
        }

        N = N + K + 2;
        M = M + K + 2;

        int curMap = 0;

    }
}