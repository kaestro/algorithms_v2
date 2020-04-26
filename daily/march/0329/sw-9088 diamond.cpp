#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

vector<int> diamonds;
int num_dia, max_gap;
int ans;

void init();
void solution();

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("C:\\Users\\didme654\\Documents\\visual studio code\\algorithms_v2\\daily\\0329\\9088.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        init();
        solution();
        cout << "#" << test_case << " " << ans << endl;
	}
	return 0;
}

void init() {
    diamonds.clear();
    cin >> num_dia >> max_gap;
    ans = 0;

    diamonds = vector<int>(num_dia, 0);
    for (int i = 0; i < num_dia; ++i) {
        cin >>diamonds[i];
    }
    sort(begin(diamonds), end(diamonds));
}

void solution() {
    int lhs = 0, rhs = 0;
    for (;lhs < num_dia; ++lhs) {
        while (rhs < num_dia && diamonds[rhs] - diamonds[lhs] <= max_gap) {
            ans = max(ans, rhs - lhs + 1);
            rhs++;
        }
    }
}