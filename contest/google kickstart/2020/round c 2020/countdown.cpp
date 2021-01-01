#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int num_cnt, Avery;
        cin >> num_cnt >> Avery;
        int temp;
        bool flag = false;
        int ans = 0;
        int prev;
        for (int j = 0; j < num_cnt; ++j) {
            cin >> temp;
            if (temp == Avery) {
                flag = true;
                prev = temp;
            } else if (flag) {
                if (temp == prev - 1) {
                    if (temp == 1) ans++;
                    prev = temp;
                } else {
                    flag = false;
                }
            }
        }
        cout << "Case #" << i + 1 << ": " << ans << endl;
    }
    return 0;
}