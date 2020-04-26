#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& rows) {
        vvi res;
        for (int r_idx = 0; r_idx < rows.size(); ++r_idx) {
            auto &row = rows[r_idx];
            for (int c_idx = 0; c_idx < row.size(); ++c_idx) {
                if (res.size() > r_idx + c_idx) {
                    res[r_idx + c_idx].push_back(row[c_idx]);
                } else {
                    for (int i = res.size(); i <= r_idx + c_idx; ++i) {
                        res.push_back(vi());
                    }
                    res[r_idx + c_idx].push_back(row[c_idx]);
                }
            }
        }
        vi ans;
        for (auto row : res) {
            ans.insert(ans.end(), row.rbegin(), row.rend());
        }
        return ans;
    }
};

int main() {
    vvi nums;
    nums = {{1,2,3,4,5},{6,7},{8},{9,10,11},{12,13,14,15,16}};
    Solution s;
    auto ans = s.findDiagonalOrder(nums);
    return 0;
}