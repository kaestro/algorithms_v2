#include <bits/stdc++.h>
using namespace std;

int n, k, a[100000], diffs[100000];

void solution() {
    memset(a, 0, sizeof(a));
    memset(diffs, 0, sizeof(diffs));
    cin >> n >> k;
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0) {
            diffs[i-1] = a[i] - a[i-1];
        }
    }

    int low = 1, high = 1e9;
    while (low < high) {
        int mid = low + (high - low) / 2;
        int ksum = 0;
        for (int i = 0; i < n - 1; ++i) {
            ksum += ceil((double)diffs[i] / mid) - 1;
        }

        if (ksum <= k) {
            ans = min(mid, ans);
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
}

int main(int argc, char const *argv[])
{
    int t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 1;
    cin >> t;
    while (n <= t) {
        cout << "Case #" << n++ << ": ";
        solution();
    }
    return 0;
}
