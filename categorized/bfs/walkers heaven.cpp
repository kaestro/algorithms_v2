// https://programmers.co.kr/learn/courses/30/lessons/1832

#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

int MOD = 20170805;
const int DOWN = 0, RIGHT = 1;
const int FREE = 0, BAN = 1, STRAIGHT = 2;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int row_size, int col_size, vector<vector<int>> city_map) {
    vvvi cntRoutes = vvvi(city_map.size(), vvi(city_map[0].size(), vi(2)));
    if (city_map[0][0] == BAN) {
        return 0;
    }
    auto& goal = cntRoutes[row_size - 1][col_size - 1];

    cntRoutes[0][0] = {1, 1};
    for (int col = 1; col < col_size; ++col) {
        if (city_map[0][col - 1] == BAN) {
            cntRoutes[0][col][RIGHT] = 0;
        } else {
            cntRoutes[0][col][RIGHT] = cntRoutes[0][col - 1][RIGHT];
        }
    }

    for (int row = 1; row < row_size; ++row) {
        if (city_map[row - 1][0] == BAN) {
            cntRoutes[row][0][DOWN] = 0;
        } else {
            cntRoutes[row][0][DOWN] = cntRoutes[row - 1][0][DOWN];
        }
    }

    for (int row = 1; row < row_size; ++row) {
        for (int col = 1; col < col_size; ++col) {
            auto above = cntRoutes[row - 1][col];
            auto left = cntRoutes[row][col - 1];
            auto above_state = city_map[row - 1][col];
            auto left_state = city_map[row][col - 1];

            auto& cur = cntRoutes[row][col];
            if (above_state == FREE) {
                cur[DOWN] = above[DOWN] + above[RIGHT];
            } else if (above_state == STRAIGHT) {
                cur[DOWN] = above[DOWN];
            }

            if (left_state == FREE) {
                cur[RIGHT] = left[DOWN] + left[RIGHT];
            } else if (left_state == STRAIGHT) {
                cur[RIGHT] = left[RIGHT];
            }

            cur[DOWN] %= MOD, cur[RIGHT] %= MOD;
        }
    }

    return (goal[DOWN] + goal[RIGHT]) % MOD;
}


int main(int argc, char const *argv[])
{
    int m = 3, n = 3;
    vvi city_map = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    solution(m, n, city_map);
    return 0;
}
