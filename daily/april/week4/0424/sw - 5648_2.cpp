#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

class Atom {
public:
    int x_pos, y_pos, dir, energy;
    Atom(int x, int y, int d, int e): x_pos(x), y_pos(y), dir(d), energy(e)
        {};
};

const int OFFSET = 2000;
const int UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3;
const int l_bnd = 0 , u_bnd = 4000;

vector<Atom> atoms;
int total_energy;
//vvi board(4001, vi(4001));
int board[4001][4001];

void reset();
void init();
void solution();
void move(Atom &atom);

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("5648.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        reset();
        init();
        solution();
        cout << "#" << test_case << " " << total_energy << endl;
	}
	return 0;
}

void reset() {
    total_energy = 0;
    atoms.clear();
}

void init() {
    int atom_cnt;
    cin >> atom_cnt;
    atoms.reserve(atom_cnt);
    for (int i = 0; i < atom_cnt; ++i) {
        int x_pos, y_pos, dir, energy;
        cin >> x_pos >> y_pos >> dir >> energy;
        atoms.push_back(Atom(2 * x_pos + OFFSET, 2 * y_pos + OFFSET, dir, energy));
    }
}

void solution() {
    while (!atoms.empty()) {
        // move atom
        int size = atoms.size();
        for (int i = 0; i < size; ++i) {
            auto& temp = atoms[i];
            move(temp);
            int nx = temp.x_pos, ny = temp.y_pos;
            if (nx < l_bnd || nx > u_bnd
                || ny < l_bnd || ny > u_bnd){
                temp.energy = 0;
            } else {
                board[ny][nx] += temp.energy;
            }
        }

        // check collision
        for (int i = 0; i < size; ++i) {
            auto &temp = atoms[i];
            int nx = temp.x_pos, ny = temp.y_pos;
            if (temp.energy == 0) continue;

            if (board[ny][nx] == temp.energy){
                board[ny][nx] = 0;
                continue;
            }

            if (board[ny][nx] != temp.energy) {
                total_energy += board[ny][nx];
                board[ny][nx] = 0;
                atoms[i].energy = 0;
            }
        }

        vector<Atom> copy_atoms;
        for (int i = 0; i < size; ++i) {
            if (atoms[i].energy > 0) {
                copy_atoms.push_back(atoms[i]);
            }
        }

        atoms = copy_atoms;
    }
}

void move(Atom& atom) {
    switch (atom.dir) {
        case UP: atom.y_pos++; break;
        case DOWN: atom.y_pos--; break;
        case LEFT: atom.x_pos--; break;
        case RIGHT: atom.x_pos++; break;
    }
}