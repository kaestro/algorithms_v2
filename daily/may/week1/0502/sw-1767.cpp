#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

class Core{
public:
    Core(int r, int c):row(r), col(c){}
    int row, col;
};

class Path{
public:
    Path(int d, int c): dir(d), cnt(c){}
    int dir, cnt;
};

const int board_limit = 12;
const int UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

bool used[board_limit][board_limit];
vector<Core> cores;
int board_size;
int max_cores, min_wires;

void reset();
void init();
void solution(int idx, int core_cnt, int wire_length);
void use_path(int core_idx, Path path);
void unuse_path(int core_idx, Path path);

vector<Path> find_path(int core_idx);

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        reset();
        init();
        solution(0, 0, 0);
        cout << "#" << test_case << " " << min_wires << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void reset() {
    min_wires = board_limit * board_limit, board_size = 0, max_cores = 0;
    cores.clear();
    memset(used, 0, sizeof(used));
}

void init() {
    cin >> board_size;
    for (int row = 0; row < board_size; ++row) {
        for (int col = 0; col < board_size; ++col) {
            cin >> used[row][col];
            if (used[row][col] && !(row == 0 || row == board_size - 1 || col == 0 || col == board_size - 1))
                cores.push_back(Core(row, col));
        }
    }
}

void solution(int idx, int core_cnt, int wire_length) {
    if (idx == cores.size()) {
        if (core_cnt > max_cores) {
            max_cores = core_cnt;
            min_wires = wire_length;
        } else if (core_cnt == max_cores)
            min_wires = min(min_wires, wire_length);
        return;
    }

    auto paths = find_path(idx);
    if (paths.empty()) {
        solution(idx + 1, core_cnt, wire_length);
    } else {
        core_cnt++;
        for (auto path : paths) {
            use_path(idx, path);
            solution(idx + 1, core_cnt, wire_length + path.cnt);
            unuse_path(idx, path);
        }
    }
}

vector<Path> find_path(int core_idx) {
    auto core = cores[core_idx];
    vector<Path> paths;
    for (int dir = 0; dir < 4; ++dir) {
        int row = core.row + dr[dir], col = core.col + dc[dir];
        int cnt = 0;
        while (row >= 0 && row < board_size && col >= 0 && col < board_size) {
            if (!used[row][col]) {
                cnt++;
                row += dr[dir], col += dc[dir];
            } else {
                break;
            }
        }

        if (row < 0 || row == board_size || col < 0 || col == board_size)
            paths.push_back(Path(dir, cnt));
    }
    return paths;
}

void use_path(int core_idx, Path path) {
    int dir = path.dir, cnt = path.cnt;
    int row = cores[core_idx].row, col = cores[core_idx].col;
    for (int i = 0; i < cnt; ++i) {
        row += dr[dir], col += dc[dir];
        used[row][col] = true;
    }
}

void unuse_path(int core_idx, Path path) {
    int dir = path.dir, cnt = path.cnt;
    int row = cores[core_idx].row, col = cores[core_idx].col;
    for (int i = 0; i < cnt; ++i) {
        row += dr[dir], col += dc[dir];
        used[row][col] = false;
    }
}