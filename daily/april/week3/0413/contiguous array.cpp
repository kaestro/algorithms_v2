#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int size = nums.size();
        int offset = size;
        vector<int> subsum_idx(2 * size + 1, -1);
        vector<int> subsum(size, -1);
        subsum[0] += 2 * nums[0];
        for (int i = 0; i < size - 1; ++i) {
            if (nums[i + 1] == 1) subsum[i + 1] = 1;
            subsum[i + 1] += subsum[i];
        }

        for (int i = 0; i < size; ++i) {
            if (subsum_idx[subsum[i] + offset] == -1)
                subsum_idx[subsum[i] + offset] = i;
        }

        int ans = 0;

        for (int i = 0; i < size; ++i) {
            if (subsum[i] == 0) ans = i + 1;
            else {
                ans = max(ans, i - subsum_idx[subsum[i] + offset]);
            }
        }


        return ans;
    }
};

int main() {
    Solution S;
    vector<int> nums = {0, 0, 0, 1, 1, 0};
    auto ans = S.findMaxLength(nums);
    return 0;
}