//Kth Smallest sum of continuous subarrays of positive numbers

#include <algorithm>
#include <vector>

using namespace std;

int find_rank(const vector<int>& preset_sums, int target_num) {
    int sum_before_target = 0;
    int cnt = 0;
    for (int i = 0; i < preset_sums.size(); ++i) {
        cnt += upper_bound(preset_sums.begin(), preset_sums.end(), target_num + sum_before_target)
                - preset_sums.begin() - i;
        sum_before_target = preset_sums[i];
    }
    return cnt;
}

int solution(vector<int> nums, int rank) {
    int start = 0, end = 0;
    int answer = 0;
    vector<int> preset_sums;
    preset_sums.reserve(nums.size());
    int subset_sum = 0;
    for (auto num : nums) {
        subset_sum += num;
        preset_sums.push_back(subset_sum);
    }
    end = int(preset_sums.back());
    while (start < end) {
        int mid = (start + end) / 2;
        int mid_rank = find_rank(preset_sums, mid);
        if (mid_rank < rank) {
            start = mid + 1;
        } else {
            answer = mid;
            end = mid - 1;
        }
    }
    return end;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    auto ans = solution(nums, 4);
    return 0;
}