#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    int max_step;
    vector<string> res;
    void backtrack(int step, string prev, int sum_s) {
        if (step == max_step) {
            if (sum_s == 0) res.push_back(prev);
            return;
        }

        if (sum_s == 0) {
            backtrack(step + 1, prev + "(", -1);
        } else {
            backtrack(step + 1, prev + ")", sum_s + 1);
            backtrack(step + 1, prev + "(", sum_s - 1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        res.clear();
        max_step = 2 * n;
        backtrack(0, "", 0);
        return res;
    }
};

int main() {
    Solution S;
    auto ans = S.generateParenthesis(3);
    for (auto tmp : ans) {
        cout << tmp << endl;
    }
    return 0;
}