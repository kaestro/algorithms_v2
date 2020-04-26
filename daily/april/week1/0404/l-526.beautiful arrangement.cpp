#include <bitset>
#include <iostream>

using namespace std;

class Solution {
public:
    bitset<15> ans;
    int res;
    int countArrangement(int N) {
        ans = (1 << N) - 1;
        res = 0;
        backtrack(N, 0, 0);

        return res;
    }

    void backtrack(int ub, int pos, bitset<15> visited) {
        if (visited == ans) {
            res++;
        }

        for (int i = 1; i <= ub; ++i) {
            if (!visited[i] && ((i - 1) == pos || i % pos == 0)) {
                backtrack(ub, pos+1, visited |= (1 << i-1));
            }
        }
    }
};

int main() {
    Solution S;
    for (int i = 1; i <= 15;++i)
        cout << i << "th: " << S.countArrangement(i) << endl;
    return 0;
}