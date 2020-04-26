#include <vector>
#include <string.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> max_coins;
public:
    int maxCoins(vector<int>& nums) {
        int num_size = nums.size();
        if (num_size == 0) return 0;

        for (int i = 0; i < num_size; ++i) {
            max_coins[i][i] = nums[i];
        }
    }

    void init(int num_size) {
        max_coins = vector<vector<int>>(num_size);
        for (int i = 0; i < num_size; ++i) {
            max_coins[i] = vector<int>(-1, num_size);
        }
    }
};