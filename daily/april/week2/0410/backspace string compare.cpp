#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> left, right;
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == '#') {
                if(!left.empty()) left.pop();
            }
            else left.push(S[i]);
        }
        
        for (int i = 0; i < T.length(); ++i) {
            if (T[i] == '#') {
                if(!right.empty()) right.pop();
            }
            else right.push(T[i]);
        }

        if (left.size() != right.size()) return false;
        
        while (!left.empty()) {
            if (left.top() != right.top()) return false;
            left.pop(), right.pop();
        }
        
        return true;
    }
};

int main() {
    Solution S;
    string lhs = "a##c", rhs = "#a#c";
    S.backspaceCompare(lhs, rhs);
    return 0;
}