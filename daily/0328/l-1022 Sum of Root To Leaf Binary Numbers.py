import sys

sys.path.append("C:\\Users\\didme654\\Documents\\visual studio code\\algorithms_v2\\daily\\freq_methods")

import listToTree

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def __init__(self):
        self.res = 0

    def sumRootToLeaf(self, root: TreeNode) -> int:
        self.helper(root, 0)
        return self.res
        
    def helper(self, root: TreeNode, prev: int) -> None:
        cur = 2 * prev + root.val
        if not root.left and not root.right:
            self.res += cur
        else:
            if root.left:
                self.helper(root.left, cur)
            if root.right:
                self.helper(root.right, cur)


if __name__ == "__main__":
    S = Solution()
    tree = [1,0,1,0,1,0,1]
    root = listToTree.listToTree(tree)
    print(S.sumRootToLeaf(root))