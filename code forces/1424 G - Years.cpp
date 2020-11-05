#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define pii pair<int, int>

using namespace std;

int main() {
    int cnt;
    cin >> cnt;
    vector<pii> year_diff;
    for (int i = 0; i < cnt; ++i) {
        int start, end;
        cin >> start >> end;
        year_diff.push_back(pii(start, 1));
        year_diff.push_back(pii(end, -1));
    }

    sort(year_diff.begin(), year_diff.end());
    int cur = 0;
    int year = 1, max_population = 0;

    for (auto& yd : year_diff) {
        cur += yd.second;
        if (cur > max_population) {
            max_population = cur;
            year = yd.first;
        }
    }

    cout << year << " " << max_population << endl;

    return 0;
}