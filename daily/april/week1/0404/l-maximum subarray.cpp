#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0xffffffff;
        if (nums.size() == 1) return nums[0];
        vector<int> subsum = vector<int>(nums.size());
        subsum[0] = nums[0];

        int res = subsum[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (subsum[i-1] <= 0) {
                subsum[i] = nums[i];
            } else {
                subsum[i] = subsum[i-1] + nums[i];
            }
            res = max(subsum[i], res);
        }
        return res;
    }
};