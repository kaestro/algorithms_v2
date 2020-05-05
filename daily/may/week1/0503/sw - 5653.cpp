#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

class Cell {
public:
    Cell(int r, int c, int hp):
        row(r), col(c), lifetime(0), healthPoint(hp) {}
    int row, col, lifetime, healthPoint;

    bool isActive() {
        return lifetime >= healthPoint && lifetime < 2 *healthPoint;
    }

    bool isDead() {
        return lifetime == 2 * healthPoint;
    }
};

set<ii> used_points;
vector<Cell> cur_cells;
int time_limit;

const int UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;
const int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};

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
    cur_cells.clear();
    used_points.clear();
}

void init() {
    int row_size, col_size;
    cin >> row_size >> col_size >> time_limit;
    for (int row = 0; row < row_size; ++row) {
        for (int col = 0; col < col_size; ++col) {
            int hp;
            cin >> hp;
            if (hp) {
                used_points.insert({row, col});
                cur_cells.push_back(Cell(row, col, hp));
            }
        }
    }
}

int solution() {
    for (int time = 0; time < time_limit; ++time) {
        map<ii, int> next_cells;
        auto it = cur_cells.begin();
        while (it != cur_cells.end()) {
            if (it->isActive()) {
                for (int dir = 0; dir < 4; ++dir) {
                    int row = it->row + dr[dir], col = it->col + dc[dir];
                    if (used_points.find({row,col}) != used_points.end()) continue;

                    next_cells[{row, col}] = max(next_cells[{row, col}], it->healthPoint);
                }
            } 
            it->lifetime++;

            if (it->isDead()) it = cur_cells.erase(it);
            else it++;
        }

        auto nit = next_cells.begin();
        while (nit != next_cells.end()) {
            used_points.insert(nit->first);
            cur_cells.push_back(Cell(nit->first.first, nit->first.second, nit->second));
            nit++;
        }


        continue;
    }
    return cur_cells.size();
}