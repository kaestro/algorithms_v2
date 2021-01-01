#include <iostream>
#include <stdlib.h>

using namespace std;

void test_case() {
    int n, k;
    scanf("%d%d", &n, &k);
    int answer = 0;
    int nxt = k;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (x != nxt) {
            nxt = k;
        }

        if (x == nxt) {
            nxt--;
            if (nxt == 0) {
                answer++;
                nxt = k;
            }
        }
    }
    printf("%d\n", answer);
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