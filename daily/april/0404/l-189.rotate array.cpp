#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int num_rot = k % nums.size();
        reverse(nums.begin(), nums.end() - num_rot);
        reverse(nums.end() - num_rot, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

int main() {
    vector<int> nums = {
        1,2,3,4,5,6,7
    };
    Solution S;
    S.rotate(nums, 3);
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}