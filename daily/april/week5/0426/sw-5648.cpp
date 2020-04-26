#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Atom {
public:
    Atom(int x, int y, int dir, int e)
        : x(x), y(y), dir(dir), energy(e) {}
    int energy;
    int x, y;
    int dir;
};

const int u_bnd = 4000, l_bnd = 0;
const int board_size = 4001, OFFSET = 2000;
const int UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3;

int board[board_size][board_size];
vector<Atom> atoms;
int ans;

void reset();
void init();
void solution();
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
        solution();
        cout << "#" << test_case << " " << ans << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void reset() {
    // memset(board, 0, sizeof(board));
    atoms.clear();
    ans = 0;
}

void init() {
    int num_atoms;
    cin >> num_atoms;
    atoms.reserve(num_atoms);
    for (int i = 0; i < num_atoms; ++i) {
        int x, y, dir, energy;
        cin >> x >> y >> dir >> energy;
        x = 2 * x + OFFSET, y = 2 * y + OFFSET;
        atoms.push_back(Atom(x, y, dir, energy));
    }
}

void solution() {
    while (!atoms.empty()) {
        int n = atoms.size();
        for (int i = 0; i < n; ++i) {
            Atom &atom = atoms[i];
            move(atom);
            board[atom.x][atom.y] += atom.energy;
        }

        for (int i = 0; i < n; ++i) {
            Atom &atom = atoms[i];
            if (atom.energy == 0) continue; // un_necessary

            int x = atom.x, y = atom.y;
            if (board[x][y] != atom.energy) {
                ans += board[x][y];
                atom.energy = 0;
            }
            board[x][y] = 0;
        }

        vector<Atom> copy_atoms;
        copy_atoms.reserve(n);
        for (int i = 0; i < n; ++i) {
            Atom &atom = atoms[i];
            if (atom.energy > 0) copy_atoms.push_back(atom);
        }
        atoms = copy_atoms;
    }
}

void move(Atom &atom) {
    switch (atom.dir) {
        case UP:
            if (atom.y == u_bnd) atom.energy = 0;
            else atom.y++;
            break;
        case DOWN:
            if (atom.y == l_bnd) atom.energy = 0;
            else atom.y--;
            break;
        case LEFT:
            if (atom.x == l_bnd) atom.energy = 0;
            else atom.x--;
            break;
        case RIGHT:
            if (atom.x == u_bnd) atom.energy = 0;
            else atom.x++;
            break;
    }
}