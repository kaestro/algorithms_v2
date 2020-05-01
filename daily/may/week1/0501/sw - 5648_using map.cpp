#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ii = pair<int, int>;

const int u_bnd = 2000, l_bnd = -2000;
const int UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3;

class Atom {
public:
    Atom(int d, int e)
        :energy(e), direction(d) {}
    Atom(){}
    int energy, direction;
};

map<ii, Atom> atoms;

void reset();
void init();
int solution();
ii move(const ii pos, Atom &atom);
bool out_boundary(ii pos);

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        reset();
        init();
        cout << "#"  << test_case << " " << solution() << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void reset() {
    atoms.clear();
}

void init() {
    int num_atoms;
    cin >> num_atoms;
    for (int i = 0; i < num_atoms; ++i) {
        int row, col, dir, energy;
        cin >> row >> col >> dir >> energy;
        atoms[{row * 2, col * 2}] = Atom(dir, energy);
    }
}

int solution() {
    int total_energy = 0;

    while (!atoms.empty()) {
        map<ii, int> board;
        map<ii, Atom> copy_atom;
        // move atoms
        auto it = atoms.begin();
        while (it != atoms.end()) {
            ii next_pos = move(it->first, it->second);
            if (!out_boundary(next_pos)) {
                board[next_pos] += it->second.energy;
                copy_atom[next_pos] = Atom(it->second.direction, it->second.energy);
            }
            it++;
        }

        it = copy_atom.begin();
        while (it != copy_atom.end()) {
            auto grid = board[it->first];
            if (board[it->first] != it->second.energy) {
                total_energy += board[it->first];
                board[it->first] = 0;
                it = copy_atom.erase(it);
            } else {
                board[it->first] = 0;
                it++;
            }
        }
        atoms = copy_atom;
    }

    return total_energy;
}

ii move(const ii pos, Atom &atom) {
    ii next_pos = pos;
    switch (atom.direction) {
        case UP: next_pos.second++; break;
        case DOWN: next_pos.second--; break;
        case LEFT: next_pos.first--; break;
        case RIGHT: next_pos.first++; break;
    }
    return next_pos;
}

bool out_boundary(ii pos) {
    return pos.first < l_bnd || pos.first > u_bnd || pos.second < l_bnd || pos.second > u_bnd;
}