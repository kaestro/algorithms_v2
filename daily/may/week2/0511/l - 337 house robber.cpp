#include <algorithm>
#include <unordered_map>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    unordered_map<TreeNode *, int> node_val;
public:
    int rob(TreeNode* root) {
        if (!root) return 0;
        if (node_val.find(root) != node_val.end()) return node_val[root];

        int val = root->val;

        if (root->left) {
            val += rob(root->left->left) + rob(root->left->right);
        }

        if (root->right) {
            val += rob(root->right->left) + rob(root->right->right);
        }

        return node_val[root] = max(val, rob(root->left) + rob(root->right));
    }
};

int main() {
    TreeNode* one = new TreeNode(3);
    one -> left = new TreeNode(2);
    one ->right = new TreeNode(3);
    one -> left -> right = new TreeNode(3);
    one -> right -> right = new TreeNode(1);

    Solution s;
    auto ans = s.rob(one);

    return 0;
}