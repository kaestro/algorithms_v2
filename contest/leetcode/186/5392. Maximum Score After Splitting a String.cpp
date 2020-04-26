#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxScore(string s) {
        int left = 0, right = 0;
        for (auto c : s) {
            right += (c == '1');
        }

        int res = right;
        for (int i = 0; i < s.length(); ++i) {
            left += '1' - s[i];
            right += '0' - s[i];
            res = max(res, left + right);
        }

        return res;
    }
};