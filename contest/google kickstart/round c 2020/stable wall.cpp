#include <iostream>
#include <vector>

using namespace std;

const int nax = 1005;
char grid[nax][nax];

void test_case() {
    int h, w;
    scanf("%d%d", &h, &w);
    for (int row = h - 1; row >= 0; --row) {
        scanf("%s", grid[row]);
    }
    string s;
    vector<bool> taken(26);
    for (int rep = 0; rep < 26; ++rep) {
        vector<bool> ok(26);
        for (int row = 0; row < h; ++row) {
            for (int col = 0; col < w; ++col) {
                if (!taken[grid[row][col] - 'A']) {
                    ok[grid[row][col] - 'A'] = true;
                }
            }
        }

        for (int col = 0; col < w; ++col) {
            int row = 0;
            while (row < h && taken[grid[row][col] - 'A']) {
                row++;
            }
            if (row == h) {
                continue;
            }
            while (row + 1 < h && grid[row][col] == grid[row + 1][col]) {
                row++;
            }

            // this is where hole is detected. You create the wall from the right.
            // If there's a wall, ok will be changed into false here.
            for (int i = row + 1; i < h; ++i) {
                ok[grid[i][col] - 'A'] = false;
            }
        }

        for (int i = 0; i < 26; ++i) {
            if (ok[i]) {
                s += char('A' + i);
                taken[i] = true;
            }
        }
    }

    bool ok = true;
    for (int row = 0; row < h; ++row) {
        for (int col = 0; col < w; ++col) {
            if (!taken[grid[row][col] - 'A']) {
                ok = false;
            }
        }
    }
    if (ok) {
        printf("%s\n", s.c_str());
    } else {
        puts("-1");
    }
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