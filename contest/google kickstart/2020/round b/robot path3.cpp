#include <iostream>
#include <vector>

#define sz(x) (int)(x.size())

using namespace std;

typedef long long ll;

struct Dir {
	ll N, E, S, W, L;
};

const ll MOD = 1e9;

void check(ll& x) {
	if(x < 1) x = (1e9 + x);
	else if(x > 1e9) x = (x - 1e9);
}

void move(char& move, ll& w, ll& h) {
	if(move == 'N') h--;
	else if(move == 'S') h++;
	else if(move == 'W') w--;
	else if(move == 'E') w++;
	
	check(w), check(h);
}

void keep(char& move, Dir& d) {
	if(move == 'N') d.N++;
	else if(move == 'E') d.E++;
	else if(move == 'S') d.S++;
	else if(move == 'W') d.W++;
}

void apply(Dir& d, ll& w, ll& h) {
	d.W = (d.W * d.L) % MOD, d.E = (d.E * d.L) % MOD;
	d.N = (d.N * d.L) % MOD, d.S = (d.S * d.L) % MOD;
	
	w += (d.E - d.W), h += (d.S - d.N);
	check(w), check(h);
}

int main() {
	int T;
	cin >> T;
	
	for(int tc = 1; tc <= T; tc++) {
		string moves;
		cin >> moves;
		
		vector<Dir> D;
		ll W = 1, H = 1;
		for(int i = 0; i < sz(moves); i++) {
			if(moves[i] >= '2' && moves[i] <= '9') {
				Dir d{0, 0, 0, 0, moves[i] - '0'};
				D.push_back(d);
			} else if(moves[i] >= 'A' && moves[i] <= 'Z') {
				if(D.empty()) {
					move(moves[i], W, H);
				} else {
					keep(moves[i], D.back());
				}
			} else if(moves[i] == ')') {
				// closing
				
				if(D.size() == 1) {
					// is last one
					apply(D.back(), W, H);
					D.pop_back();
				} else {
					Dir last = D.back();
					D.pop_back();
					
					D.back().N += (last.N * last.L) % MOD;
					D.back().E += (last.E * last.L) % MOD;
					D.back().S += (last.S * last.L) % MOD;
					D.back().W += (last.W * last.L) % MOD;
					
					D.back().N %= MOD, D.back().E %= MOD;
					D.back().S %= MOD, D.back().W %= MOD;
				}
			}
		}
		
		cout << "Case #" << tc << ": " << W << ' ' << H << '\n';
	}

	return 0;
}