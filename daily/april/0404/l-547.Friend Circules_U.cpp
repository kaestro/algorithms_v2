#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<int> parents;
    int find_parent(int child) {
        return parents[child] == child ? child : parents[child] = find_parent(parents[child]);
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size();

        parents = vector<int>(n,0);
        for (int i = 0; i < n; ++i) parents[i] = i;

        int groups = n;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (M[i][j]) {
                    int parent1 = find_parent(i);
                    int parent2 = find_parent(j);
                    if (parent1 != parent2) {
                        parents[parent2] = parent1;
                        groups--;
                    }
                }
            }
        }
        return groups;
    }
};

int main() {
    Solution S;
    vector<vector<int>> children = {
        {1,1,0},
        {1,1,1},
        {0,1,1}
    };
    auto ans = S.findCircleNum(children);
    cout << ans << endl;
    return 0;
}