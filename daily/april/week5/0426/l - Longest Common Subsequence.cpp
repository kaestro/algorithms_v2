#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int t1_len = text1.length();
        int t2_len = text2.length();
        vvi dp(t1_len, vi(t2_len));

        char c1 = text1[0];
        int t2_idx;
        for (t2_idx = 0; t2_idx < t2_len; ++t2_idx) {
            if (c1 == text2[t2_idx]) break;
        }

        if (t2_idx != t2_len) {
            for (int i = t2_idx; i < t2_len; ++i) {
                dp[0][i] = 1;
            }
        }

        int t1_idx;
        char c2 = text2[0];
        for (t1_idx = 0; t1_idx < t1_len; ++t1_idx) {
            if (c2 == text1[t1_idx]) break;
        }

        if (t1_idx != t1_len) {
            for (int i = t1_idx; i < t1_len; ++i) {
                dp[i][0] = 1;
            }
        }

        for (int row = 1; row < t1_len; ++row) {
            for (int col = 1; col < t2_len; ++col) {
                if (text1[row] == text2[col]) {
                    dp[row][col] = dp[row - 1][col - 1] + 1;
                } else {
                    dp[row][col] = max(dp[row - 1][col], dp[row][col - 1]);
                }
            }
        }

        return dp[t1_len - 1][t2_len - 1];
    }
};

int main() {
    Solution s;
    auto ans = s.longestCommonSubsequence("abc", "def");
    return 0;
}