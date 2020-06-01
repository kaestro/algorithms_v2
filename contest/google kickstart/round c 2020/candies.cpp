#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int query(vector<int> &candies, int l_idx, int r_idx) {
    int sum = 0;
    int weight = 1;
    int sign = 1;
    for (int i = l_idx; i <= r_idx; ++i) {
        sum += sign * candies[i] * weight;
        sign *= -1;
        weight++;
    }
    return sum;
}


int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; ++i) {
        int N, Q;
        cin >> N >> Q;
        int ans = 0;
        vector<int> candies(N);
        for (int j = 0; j < N; ++j) {
            cin >> candies[j];
        }

        for (int j = 0; j < Q; ++j) {
            char operation;
            cin >> operation;
            if (operation == 'Q') {
                int l_idx, r_idx;
                cin >> l_idx >> r_idx;
                ans += query(candies, l_idx - 1, r_idx - 1);
            } else {
                int candy_idx, change_into;
                cin >> candy_idx >> change_into;
                candies[candy_idx - 1] = change_into;
            }
        }
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}