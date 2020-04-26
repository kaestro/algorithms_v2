#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 0, subsum = 0;
        int size = cardPoints.size();
        if (k >= size) {
            int res = 0;
            for (auto cp : cardPoints) {
                res += cp;
            }
            return res;
        } else {
            for (int i = 0; i < k; ++i) {
                subsum += cardPoints[i];
            }
        }

        ans = 0;
        for (int i = 0; i < k - 1; ++i) {
            subsum -= cardPoints[k-1 - i];
            subsum += cardPoints[size-1 - i];
            ans = max(ans, subsum);
        }
        return ans;
    }
};

int main() {
    vector<int> cps = {1,79,80,1,1,1,200,1};
    Solution s;
    auto ans = s.maxScore(cps, 3);
    
    return 0;
}