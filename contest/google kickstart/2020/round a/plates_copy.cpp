#include <bits/stdc++.h>
using namespace std;

int n, k, p, a[30][50];
int dp[31][1501];

void solution() {
    cin >> n >> k >> p;
    memset(dp, 0xc0, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0, s = 0; j < k; ++j) {
            cin >> a[i][j];
            s += a[i][j];
            for (int l = 0; l + j + 1 <= p; ++l) {
                dp[i + 1][l + j + 1] = max(dp[i][l] + s, dp[i+1][l+j+1]);
            }
        }
    }
    cout << dp[n][p] << "\n";

}

int main(int argc, char const *argv[])
{
    int t;
    int n = 0;
    cin >> t;
    while (n < t) {
        n++;
        cout << "Case #" << n << ": ";
        solution();
    }
    return 0;
}
