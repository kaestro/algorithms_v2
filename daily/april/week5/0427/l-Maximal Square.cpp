#include <vector>
#include <algorithm>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        vvi dp(matrix.size(), vi(matrix[0].size()));
        int ans = 0;

        for (int col = 0; col < matrix[0].size(); ++col) {
            int val = (matrix[0][col] == '1');
            dp[0][col] = val;
            ans |= val;
        }
        
        for (int row = 0; row < matrix.size(); ++row) {
            int val = (matrix[row][0] == '1');
            dp[row][0] = val;
            ans |= val;
        }

        for (int row = 1; row < matrix.size(); ++row) {
            for (int col = 1; col < matrix[0].size(); ++col) {
                if (matrix[row][col] == '1') {
                    dp[row][col] = min(dp[row-1][col-1], min(dp[row][col-1],dp[row-1][col])) + 1;
                    ans = max(dp[row][col], ans);
                }
            }
        }

        return ans * ans;
    }
};

int main() {
    Solution s;
    vector<vector<char>> mat = {{'1'}};
    auto ans = s.maximalSquare(mat);
    return 0;
}