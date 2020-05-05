#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        auto prev = find(nums.begin(), nums.end(), 1);
        if (prev == nums.end()) return true;
        for (auto it = prev + 1; it != nums.end(); ++it) {
            if (*it == 1) {
                auto diff = it - prev;
                if (diff - 1 < k) return false;
                prev = it;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,0,0,0,1,0,0,1};
    int k = 2;
    auto ans = s.kLengthApart(nums, k);
    return 0;
}