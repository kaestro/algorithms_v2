#include <vector>

using namespace std;

class Solution {
private:
    vector<int> parents;

    int find_parent(int child) {
        return parents[child] == child ? child : parents[child] = find_parent(parents[child]);
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int num_nodes = edges.size();
        parents = vector<int>(num_nodes+1, 0);
        for (int i = 0; i < num_nodes+1; ++i) parents[i] = i;

        vector<int> res;
        for (auto edge : edges) {
            int parent1 = find_parent(edge[0]);
            int parent2 = find_parent(edge[1]);
            if (parent1 != parent2) {
                parents[parent2] = parent1;
            } else {
                res = edge;
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<vector<int>> edges = {
        {1,2},
        {1,3},
        {2,3}
    };
    auto ans = S.findRedundantConnection(edges);
    return 0;
}