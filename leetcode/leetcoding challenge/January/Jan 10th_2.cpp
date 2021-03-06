#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int ans = 0;
        for (auto it = instructions.begin(); it != instructions.end(); ++it) {
            sort(instructions.begin(), it);
            auto ub = upper_bound(instructions.begin(), it, *it);
            auto lb = lower_bound(instructions.begin(), it, *it);
            int left = lb - instructions.begin();
            int right = it - ub;
            ans += min(left, right);
            ans %= MOD;
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
