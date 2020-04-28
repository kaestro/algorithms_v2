#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int constrainedSubsetSum(vector<int>& nums, int k) {
    vector<int> dp(nums[0]);
    deque<int> decrease(nums[0]);
    int ans = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        if (i > k && decrease.front() == dp[i - k - 1])
            decrease.pop_front();
        
        int res = max(nums[i], decrease.front() + nums[i]);
        dp.push_back(res);

        while (!decrease.empty() && decrease.back() < res)
            decrease.pop_back();
        decrease.push_back(res);

        ans = max(ans, res);
    }
    return ans;
}