#include <iostream>
#include <algorithm>

using namespace std;

typedef long long lli;

lli solve(lli num) {
    if (num < 5) {
        return max(1ll, num - 1);
    }

    if ((num % 2 == 1) || (num % 4 == 0)) {
        return (num - solve(num - 1));
    }

    return num - solve(num / 2);
}

int main()
{
    int T;
    lli cnt, res;
    bool flag = true;

    cin >> T;
    while (T--) {
        cin >> cnt;
        res = solve(cnt);
        cout << res << endl;
    }

    return 0;
}
