#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        reverse(nums.begin(), nums.end());
        long long maxDiff = 0;
        for (int i = 0; i < n - 1; ++i) {
            maxDiff += abs(nums[i] - nums[i + 1]);
        }

        long long minDiff = maxDiff;
        for (int i = 0; i < n; ++i) {
            long long curDiff = maxDiff;
            if (i == 0) {
                curDiff -= abs(nums[0] - nums[1]);
            } else if (i == n - 1) {
                curDiff -= abs(nums[n-1] - nums[n-2]);
            } else{
                curDiff -= abs(nums[i] - nums[i - 1]) + abs(nums[i] - nums[i + 1]);
                curDiff += abs(nums[i + 1] - nums[i - 1]);
            }

            minDiff = min(minDiff, curDiff);
        }
        cout << minDiff << endl;
        continue;
    }
    return 0;
}