#include <algorithm>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int>dp(len);
        deque<int>decrease;
        decrease.push_back(nums[0]);
        dp[0] = nums[0];

        for (int i = 1; i < len; ++i) {
            if (i >= k && decrease.front() == dp[i - k]) {
                decrease.pop_front();
            }

            int num = decrease.front() + nums[i];

            while (decrease.size() > 0 && decrease.back() < num) {
                decrease.pop_back();
            }
            decrease.push_back(num);

            dp[i] = num;
        }
        return dp.back();
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,-1,-2,4,-7,3};
    int k = 2;

    nums = {10,-5,-2,4,0,3}, k = 3;

    nums = {1,-5,-20,4,-1,3,-6,-3}, k = 2;

    Solution sol;
    cout << sol.maxResult(nums, k) << endl;
    return 0;
}
