# Definition for a binary tree node.
import sys
import os

cur = os.path.dirname(__file__)
up = os.path.dirname(cur)
sys.path.append(up)

from freq_methods import listToTree

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        return self.helper(root, -sys.maxsize, sys.maxsize)
        
    
    def helper(self, root: TreeNode, bottom: int, ceil: int) -> bool:
        if root is None:
            return True
        
        if root.val <= bottom or root.val >= ceil:
            return False
        
        return self.helper(root.left, bottom, root.val) and self.helper(root.right, root.val, ceil)







if __name__ == "__main__":
    S = Solution()
    input_list = [1,2,3]
    input_list = [5,1,4,None,None,3,6]
    input_list = [10,5,15,None,None,6,20]
    input_list = [1,1]
    input_tree = listToTree.listToTree(input_list)

    print(S.isValidBST(input_tree))