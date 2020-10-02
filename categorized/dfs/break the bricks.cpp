// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRQm6qfL0DFAUo
// problem name: 5656. [모의 SW 역량테스트] 벽돌 깨기
// algorithms: dfs, backtrack, swap
// date: 10.02.2020
// purpose: review

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

const vvi directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int minBricks;
int numMarbles, width, height;
vvi board;


void init();
void solution();
void backTrack(int leftMarbles, vvi curBoard);
void dfs(vvi& nextBoard, int rowIdx, int colIdx);
void trim(vvi& nextBoard);

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        init();
        solution();
        cout << "#" << test_case << " " << minBricks << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void init() {
    cin >> numMarbles >> width >> height;
    board.clear();
    board.resize(width, vi(height));
    minBricks = width * height;
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            cin >> board[col][row];
        }
    }

    for (auto& row : board) {
        reverse(row.begin(), row.end());
    }
}

void solution() {
    backTrack(numMarbles, board);
}

void backTrack(int leftMarbles, vvi curBoard) {
    if (leftMarbles == 0) {
        int leftBricks = 0;
        for (const auto& row : curBoard) {
            for (const auto& val : row) {
                if (val != 0) ++leftBricks;
            }
        }
        minBricks = min(minBricks, leftBricks);
        return;
    }

    leftMarbles -= 1;
    
    for (int col = 0; col < width; ++col) {
        auto& column = curBoard[col];
        int row;
        for (row = height - 1; row >= 0; --row) {
            if (column[row] != 0) {
                break;
            }
        }

        vvi tempBoard = vvi(curBoard);
        if (row != -1) {
            dfs(tempBoard, row, col);
            trim(tempBoard);
        }

        backTrack(leftMarbles, tempBoard);
    }
}

void dfs(vvi& nextBoard, int rowIdx, int colIdx) {
    int blockSize = nextBoard[colIdx][rowIdx];
    nextBoard[colIdx][rowIdx] = 0;
    for (int rep = 1; rep < blockSize; ++rep) {
        for (int dir = 0; dir < 4; ++dir) {
            int nextCol = colIdx - rep * directions[dir][0];
            int nextRow = rowIdx - rep * directions[dir][1];

            if (nextCol < 0 || nextRow < 0) continue;
            if (nextCol >= width || nextRow >= height) continue;

            dfs(nextBoard, nextRow, nextCol);
        }
    }
}

void trim(vvi& nextBoard) {
    for (auto& col : nextBoard){
        int nonZeroIdx = -1;
        for (int row = 0; row < height; ++row) {
            if (col[row] != 0) {
                ++nonZeroIdx;
                swap(col[row], col[nonZeroIdx]);
            }
        }
    }
}