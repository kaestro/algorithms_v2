#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<bool> visited;
    void dfs(int node, const vector<vector<int>>& M) {
        for (int i = 0; i < M.size(); ++i) {
            if (!visited[i] && M[node][i]) {
                visited[node] = true;
                dfs(i, M);
            }
        }
    }
public:
    int findCircleNum(std::vector<std::vector<int>>& M) {
        int N = M.size();
        if (N == 0) return 0;
        visited = vector<bool>(N);
        int num_group = 0;
        for (int i = 0; i < N; ++i) {
            if (!visited[i]) {
                num_group++;
                dfs(i, M);
            }
        }
        return num_group;
    }
};

int main() {
    vector<vector<int>>M = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };
    Solution S;
    cout << S.findCircleNum(M) << endl;
    return 0;
}