#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, vector<int>> min_idx_subsum;
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;

        min_idx_subsum[0].push_back(-1);
        int subsum = 0;
        vector<int> subsums(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            subsum += nums[i];
            min_idx_subsum[subsum].push_back(i);
            subsums[i] = subsum;
        }

        for (int i = 0; i < subsums.size(); ++i) {
            auto it = min_idx_subsum.find(subsums[i] - k);
            if (it == min_idx_subsum.end()) continue;

            int cnt = 0;
            for (auto idx : it->second) {
                if (idx < i) {
                    cnt++;
                }
            }
            ans += cnt;
        }
        return ans;
    }
};

int main() {
    Solution S;
    vector<int> nums = {1,2,1,2,1};
    auto ans = S.subarraySum(nums, 3);
    return 0;
}