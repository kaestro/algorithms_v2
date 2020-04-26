#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int num_hw;
        cin >> num_hw;
        vector<ii> hws = vector<ii>(num_hw, {0,0});
        for (int i = 0; i < num_hw; ++i) {
            cin >> hws[i].second >> hws[i].first;
        }

        sort(hws.begin(), hws.end());

        int start_day = hws.back().first - hws.back().second + 1;
        hws.pop_back();

        while (!hws.empty()) {
            int ed = hws.back().first;
            int sd = ed - hws.back().second + 1;
            hws.pop_back();

            if (start_day > ed) {
                start_day = sd;
            } else {
                start_day = sd - (ed - start_day + 1);
            }
        }

        cout << "#" << test_case << " " << start_day - 1 << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}