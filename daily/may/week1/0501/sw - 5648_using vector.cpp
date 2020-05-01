#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Atom {
public:
    Atom(int x, int y, int d, int e)
        :x_pos(x), y_pos(y), dir(d), energy(e) {}
    int x_pos, y_pos, dir, energy;
};

const int map_size = 4001;
const int OFFSET = 2000;
const int l_bnd = 0, u_bnd = 4000;
const int UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3;

vector<Atom> atoms;
int board[map_size][map_size];

void reset();
void init();
int solution();
void move(Atom &atom);

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
    atoms.clear();
}

void init() {
	int num_atoms;
	cin >> num_atoms;
    atoms.reserve(num_atoms);
	for (int i = 0; i < num_atoms; ++i) {
		int x, y, dir, e;
		cin >> x >> y >> dir >> e;
		x = x * 2 + OFFSET, y = 2 * y + OFFSET;
		atoms.push_back(Atom(x, y, dir, e));
	}
}

int solution() {
	int total_energy = 0;
	while (!atoms.empty()) {
        auto it = atoms.begin();
		while (it != atoms.end()) {
            Atom &atom = *it;
			move(atom);
			if (atom.energy == 0) {
                it = atoms.erase(it);
            } else {
				board[atom.x_pos][atom.y_pos] += atom.energy;
                it++;
			}
		}

        it = atoms.begin();
		while (it != atoms.end()) {
            Atom &atom = *it;
			int &grid = board[atom.x_pos][atom.y_pos];
			if (grid != atom.energy) {
				total_energy += grid;
                it = atoms.erase(it);
			} else {
                it++;
			}
			grid = 0;
		}
	}
	return total_energy;
}

void move(Atom &atom) {
	switch (atom.dir) {
		case UP:
			if (atom.y_pos == u_bnd) atom.energy = 0;
			else atom.y_pos++;
			break;
		case DOWN:
			if (atom.y_pos == l_bnd) atom.energy = 0;
			else atom.y_pos--;
			break;
		case LEFT:
			if (atom.x_pos == l_bnd) atom.energy = 0;
			else atom.x_pos--;
			break;
		case RIGHT:
			if (atom.x_pos == u_bnd) atom.energy = 0;
			else atom.x_pos++;
			break;
	}
}