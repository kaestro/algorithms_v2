#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        vector<int> nums(N);
        for (int i = 0; i < N; ++i) {
            cin >> nums[i];
        }

        vector<int> cnt(4);
        int prev_num = nums[0];
        for (int i = 1; i < N; ++i) {
            int cur_num = nums[i];
            vector<int> next_cnt(4);
            if (cur_num == prev_num)
                continue;
            
            if (cur_num > prev_num) {
                next_cnt[3] = min(cnt[3] + 1, *min_element(cnt.begin(), cnt.begin() + 3));
                next_cnt[2] = min(*min_element(cnt.begin() + 2, cnt.end()) + 1, *min_element(cnt.begin(), cnt.begin() + 2));
                next_cnt[1] = min(*min_element(cnt.begin() + 1, cnt.end()) + 1, cnt[0]);
                next_cnt[0] = *min_element(cnt.begin(), cnt.end()) + 1;
            } else {
                next_cnt[0] = min(cnt[0] + 1, *min_element(cnt.begin() + 1, cnt.end()));
                next_cnt[1] = min(*min_element(cnt.begin(), cnt.begin() +2) + 1, *min_element(cnt.begin() + 2, cnt.end()));
                next_cnt[2] = min(*min_element(cnt.begin(), cnt.begin() + 3) + 1, cnt[3]);
                next_cnt[3] = *min_element(cnt.begin(), cnt.end()) + 1;
            }
            cnt = next_cnt;

            prev_num = cur_num;
        }

        cout << "Case " << "#" << t << ": " << *min_element(cnt.begin(), cnt.end()) << endl;
    }

    return 0;
}