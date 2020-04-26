#include <string>

using namespace std;


class Solution {
public:
    bool checkValidString(string s) {
        string stk = "";
        bool ans = true;
        auto len = stk.length();
        for (auto c : s) {
            len = stk.length();
            if (c == '(' || c == '*') {
                stk.push_back(c);
            } else {
                if (stk.empty()) {
                    ans = false;
                    break;
                }

                for (int i = stk.length() - 1; i >= 0; --i) {
                    if (stk[i] == '(') {
                        ans = true;
                        stk = stk.substr(0, i) + stk.substr(i+1);
                        break;
                    }
                }

                if (!ans) {
                    ans = true;
                    stk = stk.substr(0, stk.length() - 1);
                }
            }
        }

        if (!ans) return false;
        if (stk.empty()) return true;

        string temp;
        for (auto c : stk) {
            if (c == '(') temp.push_back('(');
            else {
                if (!temp.empty()) temp = temp.substr(0, temp.length() - 1);
            }
        }

        return temp.empty();
    }
};

int main() {
    Solution S;
    string s = "";
    s = "(*))";
    auto ans = S.checkValidString(s);
    return 0;
}