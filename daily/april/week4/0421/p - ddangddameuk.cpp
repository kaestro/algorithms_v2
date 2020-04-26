#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    for (int row = 1; row < land.size(); ++row) {
        for (int col = 0; col < land[0].size(); ++col) {
            int max_prev = 0;
            for (int p_col = 0; p_col < land[0].size(); ++p_col) {
                if (p_col == col) continue;
                max_prev = max(max_prev, land[row - 1][p_col]);
            }
            land[row][col] += max_prev;
        }
    }
    return *max_element(land[land.size() - 1].begin(), land[land.size() - 1].end());
}

int main() {
    vector<vector<int>> land = {{1,2,3,5},{5,6,7,8},{4,3,2,1}};
    auto ans = solution(land);
    return 0;
}