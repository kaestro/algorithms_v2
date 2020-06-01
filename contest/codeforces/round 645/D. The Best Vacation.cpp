#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    long long  num_months, sequential_days;
    cin >> num_months >> sequential_days;

    vector<long long > days;
    long long  total_days = 0;
    for (long long  i = 0; i < num_months; ++i) {
        long long  days_in_month;
        cin >> days_in_month;
        long long  prev_size = days.size();
        days.resize(prev_size + days_in_month);
        total_days += days_in_month;
        for (long long  j = prev_size; j < total_days; ++j) {
            days[j] = j - prev_size + 1;
        }
    }

    days.resize(total_days + sequential_days);
    copy_n(days.begin(), sequential_days, days.begin() + total_days);
    total_days += sequential_days;

    queue<long long > q_days;
    long long  ans = 0;
    long long  total_hugs = 0;
    for (long long  i = 0; i < total_days; ++i) {
        if (i >= sequential_days) {
            total_hugs -= q_days.front();
            q_days.pop();
        }

        total_hugs += days[i];
        q_days.push(days[i]);
        ans = max(ans, total_hugs);
    }

    cout << ans << endl;

    return 0;
}