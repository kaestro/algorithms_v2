#include <iostream>
#include <algorithm>

using namespace std;


struct HW {
    unsigned int deadline;
    unsigned int time;
    bool operator < (const HW &rhs) const {
        return this->deadline < rhs.deadline;
    }
};

const int MAX_HW_CNT = 1e6;
unsigned int num_hw;
struct HW hws[MAX_HW_CNT];

unsigned int solution() {
    unsigned int res = hws[num_hw - 1].deadline;
    for (int i = num_hw - 1; i >= 0; --i) {
        res = min(res, hws[i].deadline);
        res -= hws[i].time;
    }
    return res;
}

int main() {
    int num_testcase;
    cin.tie(0), ios_base::sync_with_stdio(0);
    cin >> num_testcase;
    for (unsigned int i = 1; i <= num_testcase; ++i) {
        cin >> num_hw;
        for (unsigned int j = 0; j < num_hw; ++j) {
            cin >> hws[j].time >> hws[j].deadline;
        }
        sort(hws, hws + num_hw);
        unsigned int ans = solution();
        cout << "#" << i << " " << ans << endl;
    }
    return 0;
}