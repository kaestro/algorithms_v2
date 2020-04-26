#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode *root;
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) return NULL;

        root = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); ++i) {
            TreeNode *cur = root;
            int p_val = preorder[i];

            while (true) {
                if (p_val < cur->val) {
                    if (cur->left) cur = cur->left;
                    else {
                        cur->left = new TreeNode(p_val);
                        break;
                    }
                } else if (p_val > cur->val) {
                    if (cur->right) cur = cur->right;
                    else {
                        cur->right = new TreeNode(p_val);
                        break;
                    }
                }
            }
        }

        return root;
    }
};

int main() {
    Solution S;
    vector<int> preorder =  {8,5,1,7,10,12};
    auto ans = S.bstFromPreorder(preorder);
    return 0;
}