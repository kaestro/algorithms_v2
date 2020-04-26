#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int j = i - k > 0 ? i - k : 0;
            dp[i] = dp[j];
            for (j = j + 1; j < i; ++j) {
                dp[i] = max(dp[i], dp[j]);
            }
            dp[i] = dp[i] < 0 ? nums[i] : dp[i] + nums[i];
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution s;
    vector<int> nums;
    int k;
    nums = {10,2,-10,5,20}, k = 2;
    nums = {10,-2,-10,-5,20}, k = 2;
    auto ans = s.constrainedSubsetSum(nums, k);

    return 0;
}