#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void test_case() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += abs(a[i]);
    }
    vector<int> cnt(2 * sum + 1);
    cnt[sum]++;
    int pref = 0;
    long long answer = 0;
    for (int i = 0; i < n; ++i) {
        pref += a[i];
        for (int j = 0; j * j <= sum + pref; ++j) {
            answer += cnt[sum + pref - j * j];
        }
        cnt[sum + pref]++;
    }
    printf("%lld\n", answer);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int nr = 1; nr <= T; ++nr) {
        printf("Case #%d: ", nr);
        test_case();
    }
    return 0;
}