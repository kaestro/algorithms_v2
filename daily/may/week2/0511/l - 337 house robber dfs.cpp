#include <algorithm>

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
    int helper(TreeNode* root, int &left_max, int& right_max) {
        if (!root) return 0;

        int l_left = 0, l_right = 0, r_left = 0, r_right = 0;

        left_max = helper(root->left, l_left, l_right);
        right_max = helper(root->right, r_left, r_right);

        int val = root->val + l_left + l_right + r_left + r_right;

        return max(val, left_max + right_max);
    }
public:
    int rob(TreeNode* root) {
        int l = 0, r = 0;
        return helper(root, l, r);
    }
};