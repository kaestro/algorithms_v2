#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return {};
        vector<int> ans;
        int row_end = matrix.size(), col_end = matrix[0].size();
        ans.reserve(row_end * col_end);
        int cur_row = 0, cur_col = 0;
        int prev, cur;

        while (cur_row < row_end && cur_col < col_end) {
            for (int i = cur_col; i < col_end; ++i) {
                ans.push_back(matrix[cur_row][i]);
            }
            cur_row++;

            for (int i = cur_row; i < row_end; ++i) {
                ans.push_back(matrix[i][col_end - 1]);
            }
            col_end--;

            if (cur_row < row_end) {
                for (int i = col_end - 1; i >= cur_col; --i) {
                    ans.push_back(matrix[row_end - 1][i]);
                }
                row_end--;
            }

            if (cur_col < col_end) {
                for (int i = row_end - 1; i >= cur_row; --i) {
                    ans.push_back(matrix[i][cur_col]);
                }
                cur_col++;
            }
        }

        return ans;
    }
};

int main() {
    Solution S;
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    matrix = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    auto ans = S.spiralOrder(matrix);
    for (auto num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}