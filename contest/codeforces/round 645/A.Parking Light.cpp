#include <iostream>
#include <vector>

using namespace std;

int main() {
    int test_case;
    cin >> test_case;
    for (int t = 1; t <= test_case; ++t) {
        int row, col;
        cin >> row >> col;
        int size = row * col;
        int ans;
        if (size % 2) {
            ans = size / 2 + 1;
        } else {
            ans = size / 2;
        }
        cout << ans << endl;
    }
    return 0;
}