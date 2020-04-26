#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAX_LEN = 50;

int min_raisin[MAX_LEN][MAX_LEN][MAX_LEN][MAX_LEN];
int map_raisin[MAX_LEN][MAX_LEN];
int sum_raisin[MAX_LEN][MAX_LEN];

int row_len, col_len;
int ans;

void reset();
void get_map();
void set_sum();
int get_min_raisin(int r1, int c1, int r2, int c2);
int get_sum(int r1, int c1, int r2, int c2);

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> row_len >> col_len;
        reset();
        get_map();
        set_sum();
        ans = get_min_raisin(0, 0, row_len - 1, col_len - 1);
        cout << "#" << test_case << " " << ans << endl;
	}
	return 0;
}

void reset() {
    memset(min_raisin, -1, sizeof(min_raisin));
    memset(sum_raisin, 0, sizeof(sum_raisin));
}

// not using memset
/*
void reset() {
    for (int r1 = 0; r1 < row_len; ++r1) {
        for (int r2 = r1; r2 < row_len; ++r2) {
            for (int c1 = 0; c1 < col_len; ++c1) {
                for (int c2 = c1; c2 < col_len; ++c2) {
                    if (r1 == r2 && c1 == c2) continue;
                    min_raisin[r1][c1][r2][c2] = -1;
                }
            }
        }
    }

    for (int r = 0; r < row_len; ++r) {
        for (int c = 0; c < col_len; ++c) {
            sum_raisin[r][c] = 0;
        }
    }
}
*/

void get_map() {
    for (int r = 0; r < row_len; ++r) {
        for (int c = 0; c < col_len; ++c) {
            cin >> map_raisin[r][c];
            //min_raisin[r][c][r][c] = num_raisin;
            //min_raisin[r][c][r][c] = 0;
        }
    }
}

int get_min_raisin(int r1, int c1, int r2, int c2) {
    if (r1 == r2 && c1 == c2) return 0;
    if (min_raisin[r1][c1][r2][c2] != -1) return min_raisin[r1][c1][r2][c2];

    int num_raisin = get_sum(r1, c1, r2, c2);
    int res = 0x3fffffff;
    // cut horizontally
    for (int r = r1; r < r2; ++r) {
        int temp = get_min_raisin(r1, c1, r, c2) + get_min_raisin(r+1, c1, r2, c2);
        res = min(res, temp);
    }

    // cut vertically
    for (int c = c1; c < c2; ++c) {
        int temp = get_min_raisin(r1, c1, r2, c) + get_min_raisin(r1, c+1, r2, c2);
        res = min(res, temp);
    }
    
    res += num_raisin;

    min_raisin[r1][c1][r2][c2] = res;
    return res;
}

int get_sum(int r1, int c1, int r2, int c2) {
    return sum_raisin[r1][c1] - sum_raisin[r2+1][c1] - sum_raisin[r1][c2+1] + sum_raisin[r2+1][c2+1];
}

void set_sum() {
    sum_raisin[row_len - 1][col_len - 1] = map_raisin[row_len - 1][col_len - 1];
    for (int r = row_len - 2; r >= 0; --r) {
        sum_raisin[r][col_len - 1] = sum_raisin[r + 1][col_len - 1] + map_raisin[r][col_len - 1];
    }

    for (int c = col_len - 2; c >= 0; --c) {
        sum_raisin[row_len - 1][c] = sum_raisin[row_len - 1][c + 1] + map_raisin[row_len - 1][c];
    }

    for (int r = row_len - 2; r >= 0; --r) {
        for (int c = col_len - 2; c >= 0; --c) {
            sum_raisin[r][c] = sum_raisin[r+1][c] + sum_raisin[r][c+1] - sum_raisin[r+1][c+1] + map_raisin[r][c];
        }
    }
}

//O(n**4) algorithm. needs to be out.
/*
int get_sum(int r1, int c1, int r2, int c2) {
    int res = 0;
    for (int r = r1; r <= r2; ++r) {
        for (int c = c1; c <= c2; ++c) {
            res += map_raisin[r][c];
        }
    }
    return res;
}
*/