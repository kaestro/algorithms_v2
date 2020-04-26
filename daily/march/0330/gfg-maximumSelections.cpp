#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int max_non_overlapping(vector<pair<int,int>>& ranges);

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<pair<int,int> > v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i].first >> v[i].second;

        cout << max_non_overlapping(v) << endl;
    }
    return 1;
}

// ranges[i].first is the start of ith range
// ranges[i].second is the end of ith range

bool myFunction(pair<int, int> &left, pair<int, int> &right) {
    if (left.second < right.second) return true;
    if (left.second == right.second && left.first < right.first) return true;
    return false;
}

int max_non_overlapping( vector< pair<int,int> >& ranges )
{
    sort(ranges.begin(), ranges.end(), myFunction);
    int res = 0;
    int end = -1;
    for (auto it = ranges.begin(); it != ranges.end(); ++it) {
        if (it->first < end) continue;
        end = it->second;
        res++;
    }
    return res;
}