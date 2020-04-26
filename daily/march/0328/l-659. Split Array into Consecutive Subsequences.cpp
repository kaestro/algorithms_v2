#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> num_cnt;
        unordered_map<int, int> tails;
        for (auto num : nums) {
            num_cnt[num]++;
        }

        for (auto num : nums) {
            if (num_cnt[num] == 0) continue;

            if (tails[num-1] != 0) {
                tails[num-1]--;
                tails[num]++;
                num_cnt[num]--;
            } else {
                if (num_cnt[num+1] > 0 && num_cnt[num+2] > 0) {
                    num_cnt[num+1]--, num_cnt[num+2]--, num_cnt[num]--;
                    tails[num+2]++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<int> nums = {
        1,2,3,3,4,5
    };

    Solution S;
    S.isPossible(nums);

    return 0;
}