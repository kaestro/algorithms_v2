#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

class Cell {
public:
    Cell(int row, int col, int hp)
        :row(row), col(col), hp(hp), lifetime(0) {}
    int hp, lifetime;
    int row, col;
    bool is_active() {
        return lifetime >= hp && lifetime < 2 * hp;
    }
    bool is_dead() {
        return lifetime == 2 * hp;
    }
};

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

set<ii> used;
queue<Cell> cur_cells;
int time_limit;

void reset();
void init();
int solution();

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        reset();
        init();
        cout << "#" << test_case << " " << solution() << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void reset() {
    time_limit = 0;
    used.clear();
    cur_cells = queue<Cell>();
}

void init() {
    int row_size, col_size;
    cin >> row_size >> col_size >> time_limit;
    for (int row = 0; row < row_size; ++row) {
        for (int col = 0; col < col_size; ++col) {
            int hp;
            cin >> hp;
            if (hp == 0) continue;
            cur_cells.push(Cell(row, col, hp));
            used.insert({row, col});
        }
    }
}

int solution() {
    for (int time = 0; time < time_limit; ++time) {
        int q_size = cur_cells.size();
        map<ii, int> next_cells;
        for (int i = 0; i < q_size; ++i) {
            Cell cell = cur_cells.front(); cur_cells.pop();
            if (cell.is_active()) {
                for (int d = 0; d < 4; ++d) {
                    int row = cell.row + dr[d];
                    int col = cell.col + dc[d];
                    if (used.find({row, col}) == used.end()) {
                        next_cells[{row, col}] = max(next_cells[{row, col}], cell.hp);
                    }
                }
            }
            cell.lifetime++;
            if (!cell.is_dead()) cur_cells.push(cell);
        }

        for (map<ii, int>::iterator it = next_cells.begin(); it != next_cells.end(); ++it) {
            cur_cells.push(Cell(it->first.first, it->first.second, it->second));
            used.insert(it->first);
        }
    }
    return cur_cells.size();
}