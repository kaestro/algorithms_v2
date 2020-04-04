#include <vector>
#include <iostream>
#include "../../freq_cpp_ftns/printMat.cpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res = vector<vector<int>>(n);
        for (int i = 0; i < n; ++i) {
            res[i] = vector<int>(n);
        }
        int row_lb, col_lb, row_ub, col_ub;
        row_lb = 0, col_lb = 0;
        row_ub = n, col_ub = n;
        int num = 1;
        while (row_lb < row_ub && col_lb < col_ub) {
            for (int col = col_lb; col < col_ub; ++col) {
                res[row_lb][col] = num * num;
                num++;
            }
            row_lb++;

            for (int row = row_lb; row < row_ub; ++row) {
                res[row][col_ub-1] = num * num;
                num++;
            }
            col_ub--;

            if (row_lb < row_ub) {
                for (int col = col_ub - 1; col >= col_lb; --col) {
                    res[row_ub-1][col] = num * num;
                    num++;
                }
                row_ub--;
            }

            if (col_lb < col_ub) {
                for (int row = row_ub - 1; row >= row_lb; --row) {
                    res[row][col_lb] = num * num;
                    num++;
                }
                col_lb++;
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    int n;
    cin >> n;
    auto ans = S.generateMatrix(n);
    printMat(ans);
    return 0;
}