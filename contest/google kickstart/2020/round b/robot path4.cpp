#include<cstdio>
#include<cstring>
using ll = long long;
const int MAX_N = 1e3, MOD = 1e9;
struct _offset { ll x, y; };
int dy[] = { -1,0,1,0 }, dx[] = { 0, 1, 0, -1 }, idx[26] = {}; // NESW
char d[2001];
_offset go(int L, int R) {
	_offset r{}, child;
	int i, j, o, s, e, rep;
	for (i = L; i <= R; i++) {
		if (2 <= d[i] - '0' && d[i] - '0' <= 9) {
			rep = d[i] - '0';
			i += 2;
			s = i;
			for (o = 1; o && i <= R; i++)
				if (d[i] == '(' || d[i] == ')')
					o += d[i] == '(' ? 1 : -1;
			i--;
			e = i - 1;
			child = go(s, e);
			r.x = (r.x + rep * child.x % MOD + MOD) % MOD, r.y = (r.y + rep * child.y % MOD + MOD) % MOD;
		}
		else {
			j = idx[d[i] - 'A'];
			r.x = (r.x + dx[j] + MOD) % MOD, r.y = (r.y + dy[j] + MOD) % MOD;
		}
	}
	return r;
}
int main() {
	int T, tc;
	_offset ans;
	idx['N' - 'A'] = 0, idx['E' - 'A'] = 1, idx['S' - 'A'] = 2, idx['W' - 'A'] = 3;
	scanf("%d\n", &T);
	for (tc = 1; tc <= T; tc++) {
		scanf("%s", d);
		ans = go(0, strlen(d) - 1);
		printf("Case #%d: %lld %lld\n", tc, ans.x + 1, ans.y + 1);
	}
	return 0;
}