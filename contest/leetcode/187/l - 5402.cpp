#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;
using ii = pair<int, int>;

class Solution {
private:
    deque<int> min_queue;
    deque<int> max_queue;
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l_idx = 0, u_idx;
        min_queue = deque<int>();
        max_queue = deque<int>();
        min_queue.push_back(nums[0]);
        max_queue.push_back(nums[0]);
        for (u_idx = 1; u_idx < nums.size(); ++u_idx) {
            int num = nums[u_idx];
            while (!max_queue.empty() && max_queue.back() < num)
                max_queue.pop_back();
            max_queue.push_back(num);

            while (!min_queue.empty() && min_queue.back() > num)
                min_queue.pop_back();
            min_queue.push_back(num);

            int min_val = min_queue.front();
            int max_val = max_queue.front();
            if (max_val - min_val > limit) {
                if (nums[l_idx] == min_queue.front()) min_queue.pop_front();
                else if (nums[l_idx] == max_queue.front()) max_queue.pop_front();
                l_idx++;
            }


        }
        return u_idx - l_idx;
    }
};

int main() {
    Solution s;
    vector<int> nums =  {8,2,4,7};
    int limit = 4;
    cout << s.longestSubarray(nums, limit) << "\n";
    nums = {10,1,2,4,7,2}, limit = 5;
    cout << s.longestSubarray(nums, limit) << "\n";
    nums = {4,2,2,2,4,4,2,2}, limit = 0;
    cout << s.longestSubarray(nums, limit) << "\n";
    return 0;
}