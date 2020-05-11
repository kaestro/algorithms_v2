#include <vector>

using ii = std::pair<int, int>;

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
    ii depth(TreeNode* root, int val) {
        if (!root) return {-1, -1};
        
        if (root->val == val) return {0, 0};
        
        ii left_depth = depth(root->left, val);
        ii right_depth = depth(root->right, val);
        if (left_depth.second == -1 && right_depth.second == -1) return {-1, -1};
        if (left_depth.second == 0 || right_depth.second == 0) return {root->val, 1};
        if (left_depth.second == -1) return {right_depth.first, right_depth.second + 1};
        if (right_depth.second == -1) return {left_depth.first, left_depth.second + 1};
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        ii x_depth = depth(root, x);
        ii y_depth = depth(root, y);
        if (x_depth.second != y_depth.second) return false;
        if (x_depth.first == y_depth.first) return false;
        return true;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode* one = new TreeNode(1);
    one->left = new TreeNode(2);
    one->right = new TreeNode(3);
    one->left->right = new TreeNode(4);
    Solution s;
    auto ans = s.isCousins(one, 2, 3);
    return 0;
}
