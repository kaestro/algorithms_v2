#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int ans = 0;
        int A_size = A.size();
        if (A_size == 0) return 0;
        A.insert(A.end(), A.begin(), A.end());
        vector<int> dp(A_size);
        int left_ans = A[0];
        dp[0] = A[0];
        for (int i = 1; i < A_size; ++i) {
            dp[i] = max(dp[i - 1], 0) + A[i];
            left_ans = max(left_ans, dp[i]);
        }

        int max_wrap = 0;
        for (int i = 0; i < A_size; ++i) {
            max_wrap += A[i];
            A[i] *= -1;
        }

        dp[0] = A[0];
        int right_ans = dp[0];
        for (int i = 1; i < A_size; ++i) {
            dp[i] = max(dp[i - 1], 0) + A[i];
            right_ans = max(right_ans, dp[i]);
        }

        right_ans += max_wrap;
        
        if (right_ans == 0) return left_ans;
        return max(left_ans, right_ans);
    }
};

int main() {
    vector<int> nums;
    nums = {-2, -3, -1};
    Solution s;
    auto ans = s.maxSubarraySumCircular(nums);
    return 0;
}