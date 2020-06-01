#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test_case = 0; test_case < T; ++test_case) {
        string line;
        cin >> line;
        int i, j = 0;
        int num_needed = 3;
        int cnt_num[3] = {0};
        int ans = line.length() + 1;
        for (i = 0; i < line.length(); ++i) {
            int last_char_int = line[i] - '1';
            if (num_needed > 0 && cnt_num[last_char_int]++ == 0) {
                num_needed--;
            }

            if (num_needed == 0) {
                int first_char_int = line[j] - '1';
                while (--cnt_num[first_char_int] > 0) {
                    first_char_int = line[++j] - '1';
                }
                num_needed++;

                ans = min(ans, i - j + 1);
                ++j;
                if (ans == 3) break;
            }
        }
        if (ans == line.length() + 1) cout << 0 << endl;
        else cout << ans << endl;
    }
    return 0;
}