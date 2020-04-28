#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

class cell{
public:
	cell (int hp, int r, int c):
		health_point(hp), age(0), row(r), col(c) {};
	int age, health_point;
	int row, col;
	bool is_active() {
		return age >= health_point && age < 2 * health_point;
	}
	bool is_dead() {
		return age == 2 * health_point;
	}
};

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

set<pair<int, int>> used;
vector<cell> cur_cells;

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
	used.clear();
	cur_cells.clear();
}

void init() {
	int row_end, col_end;
	cin >> row_end >> col_end;
	cin >> time_limit;
	int hp;
	for (int row = 0; row < row_end; ++row) {
		for (int col = 0; col < col_end; ++col) {
			cin >> hp;
			if (hp != 0) {
				cur_cells.push_back(cell(hp, row, col));
				used.insert({row, col});
			}
		}
	}
}

int solution() {
	for (int time = 0; time < time_limit; ++time) {
		auto it = cur_cells.begin();
		map<ii, int> next_cells;
		while (it != cur_cells.end()) {
			cell &temp = *it;
			if (temp.is_active()) {
				for (int i = 0; i < 4; ++i) {
					int row = temp.row + dr[i], col = temp.col + dc[i];
					if (used.find({row, col}) == used.end()) {
						next_cells[{row, col}] = max(next_cells[{row, col}], temp.health_point);
						used.insert({row, col});
					}
				}
			}
			temp.age++;
			if (temp.is_dead()) {
				it = cur_cells.erase(it);
				continue;
			}
			it++;
		}

		for (auto it = next_cells.begin(); it != next_cells.end(); ++it) {
			cur_cells.push_back(cell(it->second, it->first.first, it->first.second));
		}
	}

	return cur_cells.size();
}