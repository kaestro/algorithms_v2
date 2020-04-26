#include <iostream>
#include <vector>

using namespace std;

const int l_bnd = -1000, u_bnd = 1000;
const int UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3;
const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};

int total_energy, atom_cnt;

class Atom {
public:
    int dir;
    bool valid, movable;
    int row, col;
    int energy;

    Atom(int r, int c, int d, int e):
        row(r), col(c), dir(d), energy(e), valid(true), movable(true)
        {};

    void move() {
        if (!movable) return;

        switch (dir) {
            case UP:
                if (row == u_bnd) movable = false;
                else row++;
                break;
            case DOWN:
                if (row == l_bnd) movable = false;
                else row--;
                break;
            case LEFT:
                if (col == l_bnd) movable = false;
                else col--;
                break;
            case RIGHT:
                if (col == u_bnd) movable = false;
                else col++;
                break;
        }
    }
};

vector<Atom> atoms;

void reset();
void init();
void solution();
int emit_energy(int idx);
int opposite_direction(int dir);

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("5648.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        reset();
        solution();
        cout << "#" << test_case << " " << total_energy << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void reset() {
    total_energy = 0, atom_cnt = 0;
    atoms.clear();
    cin >> atom_cnt;
    atoms.reserve(atom_cnt);
    for (int i = 0; i < atom_cnt; ++i) {
        int row, col, dir, energy;
        cin >> col >> row >> dir >> energy;
        atoms.push_back(Atom(row, col, dir, energy));
    }
}

void solution() {
    while (true) {
        for (int i = 0; i < atoms.size(); ++i) {
            if (!atoms[i].movable || atoms[i].energy == 0) continue;
            atoms[i].move();
            auto energy = emit_energy(i);
            if (energy > 0)
                total_energy += energy;
        }

        int valid_atoms = 0;
        for (int i = 0; i < atoms.size(); ++i) {
            valid_atoms += atoms[i].movable * (atoms[i].energy > 0);
        }
        if (valid_atoms == 0)
            break;
    }
}

int emit_energy(int idx) {
    int ans = 0;
    for (int i = 0; i < atoms.size(); ++i) {
        if (atoms[i].energy == 0) continue;
        if (i == idx) continue;

        if (atoms[i].row == atoms[idx].row && atoms[i].col == atoms[idx].col) {
            if (i < idx || (i > idx && atoms[i].dir == opposite_direction(atoms[idx].dir))) {
                ans = atoms[i].energy + atoms[idx].energy;
                atoms[i].energy = 0;
                atoms[idx].energy = 0;
            }
        }
    }
    return ans;
}

int opposite_direction(int dir) {
    int ans;
    switch (dir) {
        case UP : ans = DOWN; break;
        case DOWN : ans = UP; break;
        case LEFT : ans = RIGHT; break;
        case RIGHT : ans = LEFT; break;
    }
    return ans;
}