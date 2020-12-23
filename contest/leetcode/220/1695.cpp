#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int lhs = 0, rhs = 0;
        set<int> used;
        int sum = nums[0];
        int maxSum = sum;
        used.insert(nums[0]);
        for (rhs = 1; rhs < nums.size(); ++rhs) {
            int num = nums[rhs];
            if (used.find(num) != used.end()) {
                while (true) {
                    int lnum = nums[lhs];
                    lhs++;
                    if (lnum == num) break;

                    used.erase(lnum);
                    sum -= lnum;
                }
            } else {
                used.insert(num);
                sum += num;
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4,2,4,5,6};
    nums = {5,2,1,2,5,2,1,2,5};
    cout <<sol.maximumUniqueSubarray(nums) << endl;
    return 0; 
}