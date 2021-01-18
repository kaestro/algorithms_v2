#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        vector<int> nums;
        int ans = 0;
        nums.reserve(instructions.size());
        for (auto inst : instructions) {
            auto ub = upper_bound(nums.begin(), nums.end(), inst);
            auto lb = lower_bound(nums.begin(), nums.end(), inst);
            int left = lb - nums.begin();
            int right = nums.end() - ub;
            ans += min(left, right);
            ans %= MOD;
            nums.insert(ub, inst);
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> instructions = {1,5,6,2};
    Solution sol;
    instructions = {1,2,3,6,5,4};
    instructions = {1,3,3,3,2,4,2,1,2};
    cout << sol.createSortedArray(instructions) << endl;
    return 0;
}
