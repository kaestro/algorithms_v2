#include <iostream>
#include <vector>

using namespace std;

class Atom{
public:
    Atom(int x, int y, int d, int e):
        x_pos(x), y_pos(y), dir(d), energy(e) {};
    int x_pos, y_pos, dir, energy;
};

const int board_size = 4001;
const int l_bnd = 0, u_bnd = 4000;
const int UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3;

vector<Atom> atoms;
int board[board_size][board_size];
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
    atoms.clear();
    ans = 0;
}

void init() {
    int atom_cnt;
    cin >> atom_cnt;
    int x_pos, y_pos, dir, energy;
    for (int i = 0; i < atom_cnt; ++i) {
        cin >> x_pos >> y_pos >> dir >> energy;
        x_pos = 2 * x_pos + 2000;
        y_pos = 2 * y_pos + 2000;
        atoms.push_back(Atom(x_pos, y_pos, dir, energy));
    }
}

void solution() {
    while (!atoms.empty()) {
        int atom_cnt = atoms.size();
        for (int i = 0; i < atom_cnt; ++i) {
            Atom &atom = atoms[i];
            move(atom);
            if (atom.energy == 0) continue;
            board[atom.x_pos][atom.y_pos] += atom.energy;
        }

        for (int i = 0; i < atom_cnt; ++i) {
            Atom & atom = atoms[i];
            int x_pos = atom.x_pos, y_pos = atom.y_pos;

            if (atom.energy != board[x_pos][y_pos]) {
                ans += board[x_pos][y_pos];
                atom.energy = 0;
            }
            board[x_pos][y_pos] = 0;
        }

        auto it = atoms.begin();
        while (it != atoms.end()) {
            if (it->energy == 0) {
                it = atoms.erase(it);
            } else {
                it++;
            }
        }
    }
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