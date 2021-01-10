#include<cstdio>
#include<cstring>
#include<cmath>
using ll = long long;
using ld = long double;
const int MAX_W = 1e5 + 1;
ld _2_fac[2 * MAX_W + 5];
ld nCr_prop(int n, int r) {
	ld nf = _2_fac[n], rf = _2_fac[r], n_rf = _2_fac[n - r];
	return pow(2., nf - rf - n_rf - n);
}
int main() {
	int T, tc, W, H, L, U, R, D, i, y, x;
	ld ans;
	for (i = 2; i < 2 * MAX_W + 5; i++)
		_2_fac[i] = _2_fac[i - 1] + log2(i);
	scanf("%d\n", &T);
	for (tc = 1; tc <= T; tc++) {
		scanf("%d%d%d%d%d%d", &W, &H, &L, &U, &R, &D);
		ans = 0;
		if (R < W) {
			y = U - 2, x = R;
			while (y >= 0) {
				ans += nCr_prop(U + R - 2, x);
				--y, ++x;
			}
		}
		if (D < H) {
			y = D, x = L - 2;
			while (x >= 0) {
				ans += nCr_prop(D + L - 2, x);
				++y, --x;
			}
		}
		printf("Case #%d: %.8Lf\n", tc, ans);
	}
	return 0;
}