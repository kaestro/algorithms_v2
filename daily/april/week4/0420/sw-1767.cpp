#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

const int maxi_lim = 12;
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};
int maxi_size; 

int maxinos[maxi_lim][maxi_lim];
bool used[maxi_lim][maxi_lim];
vector<vector<int>> cores;

int max_core_cnt, min_wire_cnt;

void init();
void backtrack(int core_idx, int core_cnt, int wire_cnt);
vector<vector<vector<int>>> find_wires(int core_idx);
bool wire_valid(vector<vector<int>> wire);
void use_wire(vector<vector<int>> wire);
void unuse_wire(vector<vector<int>> wire);

void show_used() {
    cout << "\n";
    for (int row = 0; row < maxi_size; ++row) {
        for (int col = 0; col < maxi_size; ++col) {
            cout << used[row][col] << " ";
        }
        cout << "\n";
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        init();
        backtrack(0, 0, 0);;
        cout << "#" << test_case << " " << min_wire_cnt << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void init() {
    memset(maxinos, 0, sizeof(maxinos));
    memset(used, false, sizeof(used));
    cores.clear();
    max_core_cnt = 0, min_wire_cnt = maxi_size * maxi_size;

    cin >> maxi_size;
    for (int row = 0; row < maxi_size; ++row) {
        for (int col = 0; col < maxi_size; ++col) {
            cin >> maxinos[row][col];
            if (maxinos[row][col]) {
                if (!(row == 0 || row == maxi_size - 1 || col == 0 || col == maxi_size - 1))
                    cores.push_back({row, col});
                used[row][col] = true;
            }
        }
    }
}

void backtrack(int core_idx, int core_cnt, int wire_cnt) {
    if (core_idx == cores.size()) {
        if (core_cnt == max_core_cnt) {
            min_wire_cnt = min(min_wire_cnt, wire_cnt);
        } else if (core_cnt > max_core_cnt) {
            max_core_cnt = core_cnt;
            min_wire_cnt = wire_cnt;
        }
        return;
    }

    //backtrack(core_idx + 1, core_cnt, wire_cnt);
    auto wires = find_wires(core_idx);
    for (int i = 0; i < wires.size(); ++i) {
        if(wire_valid(wires[i])) {
            use_wire(wires[i]);
            //show_used();
            backtrack(core_idx + 1, core_cnt + 1, wire_cnt + wires[i].size());
            unuse_wire(wires[i]);
            //show_used();
        }
    }

    if (wires.size() == 0)
        backtrack(core_idx + 1, core_cnt, wire_cnt);
}

vector<vector<vector<int>>> find_wires(int core_idx) {
    vector<vector<vector<int>>> res;
    if (cores[core_idx][0] == 0 || cores[core_idx][0] == maxi_size) return res;
    if (cores[core_idx][1] == 0 || cores[core_idx][1] == maxi_size) return res;

    for (int i = 0; i < 4; ++i) {
        vector<vector<int>> wire;
        int cur_row = cores[core_idx][0], cur_col = cores[core_idx][1];
        bool found = true;
        while (true) {
            int nr = cur_row + dr[i], nc = cur_col + dc[i];
            if (used[nr][nc]) {
                found = false;
                break;
            }

            wire.push_back({nr, nc});
            if (nr == 0 || nr == maxi_size - 1 || nc == 0 || nc == maxi_size - 1) break;

            cur_row = nr, cur_col = nc;
        }

        if (found) {
            res.push_back(wire);
        }
    }
    return res;
}

bool wire_valid(vector<vector<int>> wire) {
    if (wire.empty()) return false;

    for (auto node : wire) {
        if (used[node[0]][node[1]]) return false;
    }
    return true;
}

void use_wire(vector<vector<int>> wire) {
    for (auto node : wire) {
        used[node[0]][node[1]] = true;
    }
}

void unuse_wire(vector<vector<int>> wire) {
    for (auto node : wire) {
        used[node[0]][node[1]] = false;
    }
}