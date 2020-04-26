#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int res = 0;

    void helper(TreeNode* root, int num) {
        if (!root) return;

        num = num * 2 + root->val;
        if (!root->left && !root->right) res += num;
        else {
            if (root->left) helper(root->left, num);
            if (root->right) helper(root->right, num);
        }
    }

    int helper2(TreeNode* root, int prev) {
        if (!root) return 0;
        int cur = 2 * prev + root->val;
        return root->left == root->right ? cur : helper2(root->left, cur) + helper2(root->right, cur);
    }

public:
    int sumRootToLeaf(TreeNode* root) {
        helper(root, 0);
        return res;
    }

    int woRes(TreeNode* root, int num) {
        return helper2(root, 0);
    }
};