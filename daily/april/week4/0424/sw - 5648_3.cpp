#include <iostream>
#include <vector>
using namespace std;
 
struct Atom{
    int x;
    int y;
    int dir;
    int energy;
};
 
int N;
 
vector<Atom> atoms;
int map[4001][4001];
 
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
 
int calcTotalEnergy(){
    int totalEnergy = 0;
    while(!atoms.empty()){
        int size = (int)atoms.size();
        for(int i = 0; i < size; i++){
            map[atoms[i].y][atoms[i].x] = 0;
            int dir = atoms[i].dir;
            int nx = atoms[i].x + dx[dir];
            int ny = atoms[i].y + dy[dir];
            if(nx < 0 || nx > 4000 || ny < 0 || ny > 4000) {
                atoms[i].energy = 0;
                continue;
            }
            atoms[i].x = nx;
            atoms[i].y = ny;
            map[ny][nx] += atoms[i].energy;
        }
        //충돌인 지역 확인.
        for(int i = 0; i < size; i++){
            if(atoms[i].energy == 0) continue;
            int x = atoms[i].x;
            int y = atoms[i].y;
            if(map[y][x] != atoms[i].energy){
                totalEnergy += map[y][x];
                map[y][x] = 0;
                atoms[i].energy = 0;
            }
        }
        vector<Atom> tempVector;
        for (int i = 0; i < atoms.size(); ++i) {
            if (atoms[i].energy != 0) {
                tempVector.push_back(atoms[i]);
            }
        }

        atoms = tempVector;
    }
    return totalEnergy;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie();cout.tie();
    int tc;
	freopen("5648.txt", "r", stdin);
    cin >> tc;
    for(int t = 1; t <= tc; t++){
        cin >> N;
        for(int i = 0; i < N; i++){
            Atom atom;
            cin >> atom.x >> atom.y >> atom.dir >> atom.energy;
            atom.x += 1000;
            atom.y += 1000;
            atom.x *= 2;
            atom.y *= 2;
            atoms.push_back(atom);
        }
        cout << "#" << t << " " << calcTotalEnergy() << "\n";
    }
    return 0;
}