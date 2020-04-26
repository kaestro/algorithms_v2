#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int idx = -1, n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                idx = i;
                break;
            }
        }

        if (idx == -1) return *max_element(nums.begin(), nums.end());
        ans += nums[idx];

        while (idx < n) {
            vector<int> poss;
            bool flag = false;
            for (int j = idx + 1; j < n && j <= idx + k; ++j) {
                if (nums[j] > 0) {
                    flag = true;
                    ans += nums[j];
                    idx = j;
                    break;
                } else poss.push_back(nums[j]);
            }

            if (!flag) {
                auto it = max_element(poss.begin(), poss.end());
            }
        }
    }
};