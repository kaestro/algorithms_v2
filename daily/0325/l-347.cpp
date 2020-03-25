#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

using ii = pair<int, int>;

class Solution {
private:
    priority_queue<ii, vector<ii>, greater<ii>> topk;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_cnt;
        for (auto num : nums) {
            num_cnt[num]++;
        }

        for (auto it = num_cnt.begin(); it != num_cnt.end(); ++it) {
            topk.push({it->second, it->first});
            if (topk.size() > k) topk.pop();
        }

        vector<int> res;
        while (!topk.empty()) {
            res.push_back(topk.top().second);
            topk.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
};


int main(){
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    Solution S;
    auto ans = S.topKFrequent(nums, k);

    return 0;
}