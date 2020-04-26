#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int no_shift = 0;
        for (auto vec : shift) {
            no_shift += (2 * vec[0] - 1) * vec[1];
        }
        int slen = s.length();
        no_shift = no_shift / abs(no_shift) * (abs(no_shift) % slen);
        if (no_shift > 0) {
            reverse(s.begin(), s.end() - no_shift);
            reverse(s.end() - no_shift, s.end());
        } else {
            reverse(s.begin(), s.begin() - no_shift);
            reverse(s.begin() - no_shift, s.end());
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
    Solution S;
    string s = "wpdhhcj";
    vector<vector<int>> shift = {{0,7},{1,7},{1,0},{1,3},{0,3},{0,6},{1,2}};
    auto ans = S.stringShift(s, shift);
    return 0;
}