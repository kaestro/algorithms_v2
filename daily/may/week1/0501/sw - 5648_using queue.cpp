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

queue<Atom> atoms;
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
	atoms = queue<Atom>();
}

void init() {
	int num_atoms;
	cin >> num_atoms;
	for (int i = 0; i < num_atoms; ++i) {
		int x, y, dir, e;
		cin >> x >> y >> dir >> e;
		x = x * 2 + OFFSET, y = 2 * y + OFFSET;
		atoms.push(Atom(x, y, dir, e));
	}
}

int solution() {
	int total_energy = 0;
	while (!atoms.empty()) {
		int num_atoms = atoms.size();
		for (int i = 0; i < num_atoms; ++i) {
			Atom atom = atoms.front(); atoms.pop();
			move(atom);
			if (atom.energy == 0) continue;
			else {
				board[atom.x_pos][atom.y_pos] += atom.energy;
				atoms.push(atom);
			}
		}

		num_atoms = atoms.size();
		for (int i = 0; i < num_atoms; ++i) {
			Atom atom = atoms.front(); atoms.pop();
			int x_pos = atom.x_pos, y_pos = atom.y_pos;
			int &grid = board[x_pos][y_pos];
			if (grid != atom.energy) {
				total_energy += grid;
			} else {
				atoms.push(atom);
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