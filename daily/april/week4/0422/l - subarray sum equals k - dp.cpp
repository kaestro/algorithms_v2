#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> subsums(nums.size());
        int ans = 0;
        int subsum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            subsum += nums[i];
            ans += (k == subsum);
            subsums[i] = subsum;
        }

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                ans += ((subsums[j] - subsums[i]) == k);
            }
        }
        return ans;
    }
};